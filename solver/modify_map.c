/*
** EPITECH PROJECT, 2019
** modify_map.c
** File description:
** modify map
*/

#include "project.h"

void modify_map(path_t *path, char **map)
{
    path_t *curr = path;

    while (curr->next != NULL) {
        map[curr->y][curr->x] = 'o';
        curr = curr->next;
    }
    map[curr->y][curr->x] = 'o';
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    for (int i = 0; map[i] != NULL; i++) {
    	for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'o')
                map[i][j] = '*';
        }
    }
}

int count_wrong_paths(path_t *curr)
{
    int paths = 0;

    if (curr->right == 1)
        paths++;
    if (curr->left == 1)
        paths++;
    if (curr->up == 1)
        paths++;
    if (curr->down == 1)
        paths++;
    return (paths);
}

int exist(path_t *path, int x, int y)
{
    path_t *curr = path;

    for (; curr->next != NULL; curr = curr->next)
        if (curr->x == x && curr->y == y)
            return (1);
    return (0);
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
}

int check_found(path_t *curr, char **map)
{
    int x = strlen(map[0]);
    int y = 0;

    for (; map[y] != NULL; y++);
    if (curr->x == x - 1 && curr->y == y - 1)
        return (1);
    return (0);
}
