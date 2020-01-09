/*
** EPITECH PROJECT, 2019
** jump
** File description:
** jump
*/

#include "../../include/list.h"

void move_rect_jump(sfIntRect *rect, int offset, int max) {
    rect->left = (rect->left + offset) % max;
}

void jump(list_t *list)
{
    while (list->object->type != PLAYER)
        list = list->next;
}