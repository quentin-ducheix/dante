/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#include "my.h"

int main(int ac, char **av)
{
	int x = 0;
	int y = 0;

	if (ac == 3 || ac == 4) {
		x = atoi(av[1]);
		y = atoi(av[2]);
	} else
		return (84);
	if (x <= 0 || y <= 0)
		return (84);
	srand(time(NULL) * getpid());
	if (ac == 3)
		imperfect(x, y);
	else if (ac == 4 && strcmp("perfect", av[3]) == 0)
		perfect(x, y);
	else
		return (84);
	return (0);
}

void imperfect(int h, int w)
{
	maze_t *maze = malloc(sizeof(maze_t));
	int to_break = 0;

	maze->h = h;
	maze->w = w;
	maze->haut = (2 * h) - 1;
	maze->larg = (2 * w) - 1;
	to_break = (maze->h * maze->w) / 2;
	gen_maze(maze);
	maze->forw = 1;
	maze->lef = 1;
	gen_perfect(maze);
	for (int broken = 0; broken < to_break; broken++)
		maze->maze[rand() % maze->h][rand() % maze->w] = '*';
	printer(maze->maze);
}

void perfect(int h, int w)
{
	maze_t	*maze = malloc(sizeof(maze_t));

	maze->h = h;
	maze->w = w;
	maze->haut = (2 * h) - 1;
	maze->larg = (2 * w) - 1;
	gen_maze(maze);
	maze->forw = 1;
	maze->lef = 1;
	gen_perfect(maze);
	if (maze->maze[maze->h - 1][maze->w - 1] == '*' && maze->maze[maze->h - 2][maze->w - 1] == '*'
	&& maze->maze[maze->h - 1][maze->w - 2] == '*' && maze->maze[maze->h - 2][maze->w - 2] == '*')
		maze->maze[maze->h - 2][maze->w - 1] = 'X';
	printer(maze->maze);
}

void printer(char **tab)
{
	int i = 0;

	for (; tab[i + 1]; i++)
		printf("%s\n", tab[i]);
	printf("%s", tab[i]);
}

void gen_maze(maze_t *maze)
{
	int i = 0;

	maze->maze = malloc(sizeof(char *) * (maze->haut + 1));
	for (int j = 0;i < maze->haut; i++) {
		maze->maze[i] = malloc(sizeof(char) * (maze->larg + 1));
		j = 0;
		for (; j < maze->larg; j++) {
			if (j % 2 == 0 && i % 2 == 0)
				maze->maze[i][j] = '*';
			else if (j % 2 != 0 && i % 2 == 0)
				maze->maze[i][j] = 'X';
			else if (i % 2 != 0)
				maze->maze[i][j] = 'X';
		}
		maze->maze[i][j] = '\0';
	}
	maze->maze[i] = NULL;
}
