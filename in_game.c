/*
** EPITECH PROJECT, 2019
** in_game.c
** File description:
** in game part
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void move_in_game3(my_t *sok)
{
    if (sok->input == KEY_LEFT && check_x(sok->y, (sok->x - 1)) == 1 &&
    mvinch(sok->y, sok->x - 2) != 'X' && mvinch(sok->y, sok->x - 2) != '#') {
        mvaddch(sok->y, sok->x, ' ');
        sok->x -= 1;
        mvaddch(sok->y, sok->x, 'P');
        mvaddch(sok->y, sok->x - 1, 'X');
    }
    if (sok->input == KEY_RIGHT && check(sok->y, (sok->x + 1), sok) != 0) {
        mvaddch(sok->y, sok->x, ' ');
        sok->x += 1;
        mvaddch(sok->y, sok->x, 'P');
    }
    if (sok->input == KEY_RIGHT && check_x(sok->y, (sok->x + 1)) != 0 &&
    mvinch(sok->y, sok->x + 2) != 'X' && mvinch(sok->y, sok->x + 2) != '#') {
        mvaddch(sok->y, sok->x, ' ');
        sok->x += 1;
        mvaddch(sok->y, sok->x, 'P');
        mvaddch(sok->y, sok->x + 1, 'X');
    }
}

void move_in_game2(my_t *sok)
{
    if (sok->input == KEY_DOWN && check((sok->y + 1), sok->x, sok) != 0) {
        mvaddch(sok->y, sok->x, ' ');
        sok->y += 1;
        mvaddch(sok->y, sok->x, 'P');
    }
    if (sok->input == KEY_DOWN && check_x((sok->y + 1), sok->x) != 0 &&
    mvinch(sok->y + 2, sok->x) != 'X' && mvinch(sok->y + 2, sok->x) != '#') {
        mvaddch(sok->y, sok->x, ' ');
        sok->y += 1;
        mvaddch(sok->y, sok->x, 'P');
        mvaddch(sok->y + 1, sok->x, 'X');
    }
    if (sok->input == KEY_LEFT && check(sok->y, (sok->x - 1), sok) == 1) {
        mvaddch(sok->y, sok->x, ' ');
        sok->x -= 1;
        mvaddch(sok->y, sok->x, 'P');
    }
    move_in_game3(sok);
}

void move_in_game(my_t *sok)
{
    if (sok->input == KEY_UP && check((sok->y - 1), sok->x, sok) != 0) {
        mvaddch(sok->y, sok->x, ' ');
        sok->y -= 1;
        mvaddch(sok->y, sok->x, 'P');
    }
    if (sok->input == KEY_UP && check_x((sok->y - 1), sok->x) != 0 &&
    mvinch(sok->y - 2, sok->x) != 'X' && mvinch(sok->y - 2, sok->x) != '#') {
        mvaddch(sok->y, sok->x, ' ');
        sok->y -= 1;
        mvaddch(sok->y, sok->x, 'P');
        mvaddch(sok->y - 1, sok->x, 'X');
    }
    if (sok->input == ' ') {
        clear();
        printw(sok->buffer);
        sok->x = sok->x_save;
        sok->y = sok->y_save;
    }
    move_in_game2(sok);
}

void in_game(my_t *sok)
{
    find_p(sok);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    printw(sok->buffer);
    while (1) {
        sok->input = getch();
        move_in_game(sok);
        cheat_cw(sok);
        cheat_dw(sok);
        if (sok->input == 27)
            break;
    }
    endwin();
}