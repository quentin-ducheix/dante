/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#include "my.h"

int algo_2(int x, int y, int *offset, all_t *all)
{
	offset[0] = -1;
	offset[1] = 0;
	if (x - 1 >= 0 && all->maze[(y * all->height) +
	x - 1] == '*' && algo(x, y, offset, all) == 0)
		return (0);
	offset[0] = 0;
	offset[1] = -1;
	if (y - 1 >= 0 && all->maze[(y - 1) * all->height +
	x] == '*' && algo(x, y, offset, all) == 0)
		return (0);
	all->maze[y * all->height + x] = '*';
	return (1);
}

int algo(int x, int y, int *offset, all_t *all)
{
	x += offset[0];
	y += offset[1];
	all->maze[y * all->height + x] = 'o';
	if (x == all->width - 1 && y == all->height - 2)
		return (0);
	offset[0] = 0;
	offset[1] = 1;
	if (y + 1 < all->width  && all->maze[(y + 1) * all->height +
	x] == '*' && algo(x, y, offset, all) == 0)
		return (0);
	offset[0] = 1;
	offset[1] = 0;
	if (x + 1 < all->height && all->maze[y * all->height +
	x + 1] == '*' && algo(x, y, offset, all) == 0)
		return (0);
	return(algo_2(x, y, offset, all));
}

int get_it(all_t *all, char **av)
{
	int fd = open(av[1], O_RDONLY);
	struct stat inf;
	char *maze = NULL;
	int height = 0;
	int width = 1;

	if (fd <= 0)
		return (84);
	stat(av[1], &inf);
	if (inf.st_size == 0)
		return (84);
	all->maze = malloc(sizeof(char) * inf.st_size + 3);
	read(fd, all->maze, inf.st_size);
	all->maze[inf.st_size] = '\0';
	for (; all->maze[height] != '\n'; height++);
	height++;
	width = inf.st_size / (height + 1);
	width++;
	all->width = width;
	all->height = height;
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	int *offset = malloc(sizeof(int));
	int x = 0;
	all_t *all = malloc(sizeof(all_t));
	int y = 0;

	offset[0] = 0;
	offset[1] = 0;
	if (ac != 2 || get_it(all, av) == 84)
		return (84);
	if (algo(x, y, offset, all)) {
		printf("no solution found\n");
		return (84);
	}
	printf("%s", all->maze);
	return (0);
}
