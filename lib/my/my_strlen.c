/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_strlen.c
*/

#include "../../include/list.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}

void free_all(list_t **list)
{
    while ((*list)) {
        free((*list)->object);
        (*list) = (*list)->next;
    }
}