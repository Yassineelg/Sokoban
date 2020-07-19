/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of sokoban
*/

#include "my.h"
#include "Include/my.h"

void errors_gest2(int count_p, int count_x, int count_o)
{
    if (count_p != 1)
        exit(84);
    if ((count_x - count_o) < 0)
        exit(84);
}

void errors_gest(int len, my_t *sok)
{
    int i;
    int count_p = 0;
    int count_x = 0;
    int count_o = 0;

    if (len <= 0)
        exit(84);
    for (i = 0; sok->buffer[i] != '\0'; i++) {
        if (sok->buffer[i] != ' ' && sok->buffer[i] != '\n' &&
        sok->buffer[i] != '#' && sok->buffer[i] != 'X' &&
        sok->buffer[i] != 'O' && sok->buffer[i] != 'P')
            exit(84);
        if (sok->buffer[i] == 'P')
            count_p++;
        if (sok->buffer[i] == 'X')
            count_x++;
        if (sok->buffer[i] == 'O')
            count_o++;
    }
    errors_gest2(count_p, count_x, count_o);
}

void open_map(int ac, char **av, my_t *sok)
{
    struct stat mapsize;
    int fd;
    int size;
    int len;

    if (ac != 2)
        exit(84);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit(84);
    stat(av[1], &mapsize);
    size = mapsize.st_size;
    sok->buffer = malloc(sizeof(char) * size);
    len = read(fd, sok->buffer, size);
    errors_gest(len, sok);
}

int main(int ac, char **av)
{
    my_t *sok = malloc(sizeof(my_t));
    int fd;
    char buffer[187];

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        fd = open("rules", O_RDONLY);
        read(fd, buffer, 187);
        write(1, buffer, 187);
        close(fd);
    }
    else {
        open_map(ac, av, sok);
        in_game(sok);
    }
    return (0);
}