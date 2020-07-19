/*
** EPITECH PROJECT, 2019
** cheats.c
** File description:
** cheats part
*/

#include "my.h"

void cheat_dw(my_t *sok)
{
    if (sok->input == 'Z' || sok->input == 'z' &&
    mvinch(sok->y - 1, sok->x) == '#')
        mvaddch(sok->y - 1, sok->x, ' ');
    if (sok->input == 'S' || sok->input == 's' &&
    mvinch(sok->y + 1, sok->x) == '#')
        mvaddch(sok->y + 1, sok->x, ' ');
    if (sok->input == 'Q' || sok->input == 'q' &&
    mvinch(sok->y, sok->x - 1) == '#')
        mvaddch(sok->y, sok->x - 1, ' ');
    if (sok->input == 'D' || sok->input == 'd' &&
    mvinch(sok->y, sok->x + 1) == '#')
        mvaddch(sok->y, sok->x + 1, ' ');
}

void cheat_cw(my_t *sok)
{
    if (sok->input == 'O' || sok->input == 'o' &&
    mvinch(sok->y - 1, sok->x) == ' ')
        mvaddch(sok->y - 1, sok->x, 'O');
    if (sok->input == 'X' || sok->input == 'x' &&
    mvinch(sok->y + 1, sok->x) == ' ')
        mvaddch(sok->y + 1, sok->x, 'X');
    if (sok->input == 'I' || sok->input == 'i' &&
    mvinch(sok->y - 1, sok->x) == ' ')
        mvaddch(sok->y - 1, sok->x, '#');
    if (sok->input == 'K' || sok->input == 'k' &&
    mvinch(sok->y + 1, sok->x) == ' ')
        mvaddch(sok->y + 1, sok->x, '#');
    if (sok->input == 'J' || sok->input == 'j' &&
    mvinch(sok->y, sok->x - 1) == ' ')
        mvaddch(sok->y, sok->x - 1, '#');
    if (sok->input == 'L' || sok->input == 'l' &&
    mvinch(sok->y, sok->x + 1) == ' ')
        mvaddch(sok->y, sok->x + 1, '#');
}