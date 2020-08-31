/*
** EPITECH PROJECT, 2019
** solve.c
** File description:
** solve.c
*/

#include "project.h"

int count_paths(path_t *path, char **map)
{
    path_t *curr = path;
    int paths = 0;
    for (; curr->next != NULL; curr = curr->next);
    if (map[curr->y][curr->x + 1] == '*')
        paths++;
    if (map[curr->y + 1] != NULL && map[curr->y + 1][curr->x] == '*')
        paths++;
    if (curr->x != 0 && map[curr->y][curr->x - 1] == '*')
        paths++;
    if (curr->y != 0 && map[curr->y - 1][curr->x] == '*')
        paths++;
    curr->crossroads = paths;
    return (paths);
}

path_t *init_struct(char **map)
{
    path_t *path;
    path = malloc(sizeof(path_t));
    path->x = 0;
    path->y = 0;
    path->next = NULL;
    path->prev = NULL;
    path->crossroads = 1;
    path->direction = 10;
    count_paths(path, map);
    path->right = 0;
    path->down = 0;
    path->up = 0;
    path->left = 0;
    return (path);
}

int choose_path(path_t *path, char **map)
{
    path_t *curr = path;

    for (; curr->next != NULL; curr = curr->next);
    if (map[curr->y][curr->x + 1] == '*' && curr->right == 0 &&
        curr->direction != 2 && exist(path, curr->x + 1, curr->y) == 0) {
        add_to_path(path, curr->x + 1, curr->y, 0);
        return (count_paths(path, map));
    }
    if (map[curr->y + 1] != NULL && curr->direction != 3 &&
        map[curr->y + 1][curr->x] == '*' && curr->down == 0
        && exist(path, curr->x, curr->y + 1) == 0) {
        add_to_path(path, curr->x, curr->y + 1, 1);
        return (count_paths(path, map));
    }
    return (second_choice(path, map));
}

int travel(path_t *path, char **map)
{
    path_t *curr = path;
    int possible = 0;

    while (1) {
        if (possible == 1)
            backtrack(path);
        possible = choose_path(path, map);
        curr = path;
        for (; curr->next != NULL; curr = curr->next);
        if (curr->x == 0 && curr->y == 0)
            return (84);
        if (check_found(curr, map) == 1)
            return (0);
    }
    return (0);
}

int solve(char **av)
{
    char **map = make_map(av[1]);
    path_t *path = init_struct(map);
    if (map == NULL)
        return (84);
    if (travel(path, map) == 84) {
        free_map(map);
        return (84);
    }
    modify_map(path, map);
    free_map(map);
    return (0);
}
