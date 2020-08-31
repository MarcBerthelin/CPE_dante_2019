/*
** EPITECH PROJECT, 2020
** dante/generator
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int randomizer(int nb)
{
    int i = rand() % nb;

    return (i);
}

char **hole_hole(char **map, int x, int y)
{
    for (int i = 0; i != y; i++)
    {
        if ((map[i][1] == 'X') && (i != y-1))
        {
            map[i][randomizer(x)] = '*';
        }
    }
    map[y-1][x-1] = '*';
    return (map);
}

char **unperfect(char **map, int x, int y)
{
    for (int i = 0; i != (x/10); i++)
        map = hole_hole(map, x, y);
    return (map);
}

char **make_my_map(char **map, int x, int y)
{
    for (int i = 0; i != y; i++) {
        if (i%2 == 0) {
            map[i] = malloc(sizeof(char) * x+2);
            if (i < y-1)
                map[i][x] = '\n';
            map[i][x+1] = '\0';
            for (int j = 0; j != x; j++)
                map[i][j] = '*';
        } if (i%2 == 1) {
            map[i] = malloc(sizeof(char) * x+2);
            if (i < y-1)
                map[i][x] = '\n';
            map[i][x+1] = '\0';
            for (int j = 0; j != x; j++)
                map[i][j] = 'X';
        }
    }
    return (hole_hole(map, x, y));
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (84);
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    char **map = malloc(sizeof(char *) * y+1);

    map = make_my_map(map, x, y);

    if (ac == 3)
        map = unperfect(map, x, y);
    for (int i = 0; i != y; i++)
        printf(map[i]);
    free(map);
    return (0);
}
