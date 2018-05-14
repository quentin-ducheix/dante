/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct	maze_s {
	char **maze;
	int haut;
	int larg;
	int h;
	int w;
	int forw;
	int lef;
} maze_t;

void imperfect(int h, int w);
void perfect(int h, int w);
void printer(char **tab);
void gen_maze(maze_t *maze);
void breaker(maze_t *maze, int i, int j);
void gen_perfect(maze_t *maze);

#endif
