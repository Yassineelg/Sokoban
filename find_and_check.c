/*
** EPITECH PROJECT, 2019
** find.c
** File description:
** sokoban parts
*/

#include "my.h"

void find_p(my_t *sok)
{
    sok->y_save = 0;
    sok->x_save = 0;
    for (int i = 0; sok->buffer[i] != 'P'; i++, sok->x_save++) {
        if (sok->buffer[i] == '\n') {
            sok->y_save++;
            sok->x_save = 0;
            i++;
        }
    }
    sok->x = sok->x_save;
    sok->y = sok->y_save;
}

int check(int y, int x, my_t *sok)
{
    int testch = mvinch(y, x);

    if (testch == ' ' || testch == 'O')
        return (1);
    else
        return (0);
}

int check_x(int y, int x)
{
    int testch = mvinch(y, x);

    if (testch == 'X')
        return (1);
    else
        return (0);
}