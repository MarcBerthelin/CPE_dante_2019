/*
** EPITECH PROJECT, 2020
** project.h
** File description:
** project header file
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct path path_t;
struct path
{
    int x;
    int y;
    struct path *next;
    struct path *prev;
    int crossroads;
    int direction;
    int right;
    int down;
    int left;
    int up;
};

int solve(char **av);
char **make_map(char *txt);
char **my_str_to_word_array(char *str, char c);
int second_choice(path_t *path, char **map);
void free_map(char **map);
int check_found(path_t *curr, char **map);
void modify_map(path_t *path, char **map);
void add_to_path(path_t *path, int x, int y, int dir);
void backtrack(path_t *path);
int count_paths(path_t *path, char **map);
void disp_info(path_t *path);
int count_wrong_paths(path_t *curr);
int exist(path_t *path, int x, int y);