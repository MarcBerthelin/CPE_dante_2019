/*
** EPITECH PROJECT, 2019
** manage_path.c
** File description:
** manage_path.c
*/

#include "project.h"

int second_choice(path_t *path, char **map)
{
    path_t *curr = path;

    for (; curr->next != NULL; curr = curr->next);
    if (curr->x != 0 && map[curr->y][curr->x - 1] == '*' &&
        curr->left == 0 && curr->direction != 0 &&
        exist(path, curr->x - 1, curr->y) == 0) {
        add_to_path(path, curr->x - 1, curr->y, 2);
        return (count_paths(path, map));
    }
    if (curr->y != 0 && map[curr->y - 1][curr->x] == '*' &&
        curr->up == 0 && curr->direction != 1 &&
        exist(path, curr->x, curr->y - 1) == 0) {
        add_to_path(path, curr->x, curr->y - 1, 3);
        return (count_paths(path, map));
    }
    return (1);
}

void add_to_path(path_t *path, int x, int y, int dir)
{
    path_t *curr = path;

    for (; curr->next != NULL; curr = curr->next);
    curr->next = malloc(sizeof(path_t));
    curr->next->prev = curr;
    curr = curr->next;
    curr->next = NULL;
    curr->y = y;
    curr->x = x;
    curr->direction = dir;
    curr->right = 0;
    curr->down = 0;
    curr->left = 0;
    curr->up = 0;
}

void wrong_path(path_t *curr, path_t *last)
{
    if (last->x < curr->x)
        curr->left = 1;
    if (last->x > curr->x)
        curr->right = 1;
    if (last->y < curr->y)
        curr->up = 1;
    if (last->y > curr->y)
        curr->down = 1;
}

void backtrack(path_t *path)
{
    path_t *curr = path;
    path_t *last = path;

    for (; curr->next != NULL; curr = curr->next);
    last = curr;
    curr = curr->prev;
    while ((curr->crossroads == 1 || curr->crossroads == 2) &&
    curr->prev != NULL && count_wrong_paths(curr) != curr->crossroads - 1) {
        free(last);
        last = curr;
        curr = curr->prev;
    }
    wrong_path(curr, last);
    curr->next = NULL;
}
