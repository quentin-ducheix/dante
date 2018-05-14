/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct all_s {
	int height;
	int width;
	char *maze;
} all_t;

int algo(int x, int y, int *offset, all_t *all);

#endif
