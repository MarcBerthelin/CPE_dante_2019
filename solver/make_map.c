/*
** EPITECH PROJECT, 2019
** make_map.c
** File description:
** make_map.c
*/

#include "project.h"

int check_line(char *str)
{
    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] != '*' && str[j] != 'X')
            return (84);
    return (0);
}

char **check_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        if (check_line(map[i]) == 84)
            return (NULL);
    }
    if (map[0][0] != '*')
        return (NULL);
    return (map);
}

size_t read_size(char *txt)
{
    struct stat filestat;
    if (stat(txt, &filestat) != 0)
        return (0);
    return (filestat.st_size);
}

char **make_map(char *txt)
{
    int fd = 0;
    int size = read_size(txt);
    char *buff = malloc(sizeof(char) * (size + 1));
    char **map = NULL;

    fd = open(txt, O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buff, size);
    buff[size] = '\0';
    close(fd);
    map = my_str_to_word_array(buff, '\n');
    free(buff);
    return (check_map(map));
}
