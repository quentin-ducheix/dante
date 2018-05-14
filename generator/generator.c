/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#include "my.h"

void breaker(maze_t *maze, int i, int j)
{
	int k = rand() % 2;

	(i - 1 >= 0 && maze->maze[i - 1][j] == 'X') ? (maze->forw = 0) : (0);
	(j - 1 >= 0 && maze->maze[i][j - 1] == 'X') ? (maze->lef = 0) : (0);
	(i - 1 >= 0 && maze->forw == 0 && maze->lef == 1) ?
	(maze->maze[i - 1][j] = '*') : (0);
	(j - 1 >= 0 && maze->forw == 0 && maze->lef == 1) ?
	(maze->maze[i][j - 1] = '*') : (0);
	(i - 1 >= 0 && maze->maze[i - 1][j] == 'X') ? (maze->forw = 0) : (0);
	(j - 1 >= 0 && maze->maze[i][j - 1] == 'X') ? (maze->lef = 0) : (0);
	(maze->forw == 0 && maze->lef == 0 && j - 1 >= 0 && k == 0) ?
	(maze->maze[i][j - 1] = '*') : (0);
	(i - 1 >= 0 && maze->maze[i - 1][j] == 'X') ? (maze->forw = 0) : (0);
	(j - 1 >= 0 && maze->maze[i][j - 1] == 'X') ? (maze->lef = 0) : (0);
	(maze->forw == 0 && maze->lef == 0 && i - 1 >= 0 && k == 1) ?
	(maze->maze[i - 1][j] = '*') : (0);
}

void gen_perfect(maze_t *maze)
{
	int tmp = 0;
	for (int i = 0; i < maze->haut; i += 2) {
		for (int j = 0; j < maze->larg; j += 2) {
			(i == 0) ? (maze->maze[i][j] = '*') : (0);
			breaker(maze, i, j);
		}
	}
	for (int j = 0; tmp < maze->h; tmp++) {
		for (; j < maze->w; j++);
		maze->maze[tmp][j] = '\0';
	}
	maze->maze[tmp] = NULL;
	if (maze->maze[maze->h - 1][maze->w - 2] == 'X'
	&& maze->maze[maze->h - 2][maze->w - 1] == 'X')
		maze->maze[maze->h - 1][maze->w - 2] = '*';
	maze->maze[maze->h - 1][maze->w - 1] = '*';
	for (int j = 0; j < maze->w; j++)
		maze->maze[0][j] = '*';
	for (int i = 0; i < maze->h; i++)
		maze->maze[i][0] = '*';
}
