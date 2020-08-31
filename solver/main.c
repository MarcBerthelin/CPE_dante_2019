/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "project.h"

int main(int ac, char **argv)
{
    if (ac != 2)
        return (84);
    if (solve(argv) == 84)
        return (84);
    return 0;
}
