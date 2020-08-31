/*
** EPITECH PROJECT, 2020
** str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include <stdlib.h>

int word_count(char *str, char c)
{
    int c_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c || str[i] == '\n')
            c_count++;
    return (c_count);
}

int word_length(char *str, int i, char c)
{
    int length = 0;
    for (; (str[i] != '\n' && str[i] != c) && str[i] != '\0'; i++)
        length++;
    return (length);
}

char **my_str_to_word_array(char *str, char c)
{
    int c_count = word_count(str, c) + 1;
    int j = 0;
    int word_size = 0;
    char **tab = malloc(sizeof(char *) * (c_count + 1));

    tab[c_count] = NULL;
    for (int i = 0; i != c_count; i++) {
        word_size = word_length(str, j, c);
        tab[i] = malloc(sizeof(char) * (word_size + 1));
        tab[i][word_size] = '\0';
        for (int y = 0; y != word_size; y++) {
            tab[i][y] = str[j];
            j++;
        }
        j++;
    }
    return (tab);
}
