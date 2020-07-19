/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes.
*/
#ifndef MY_H
#define MY_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct my_struct_s {
    char *buffer;
    int x;
    int y;
    int o;
    int h;
    int l;
    int x_save;
    int y_save;
    int input;
} my_t;

void cheat_dw(my_t *sok);
void cheat_cw(my_t *sok);
void find_p(my_t *sok);
void move_in_game3(my_t *sok);
void move_in_game2(my_t *sok);
void move_in_game(my_t *sok);
void in_game(my_t *sok);
int check(int y, int x, my_t *sok);
int check_x(int y, int x);

#endif