/*
** EPITECH PROJECT, 2020
** collision.c
** File description:
** collision.c
*/

#include "../../include/list.h"

int collision_x(list_t *list, list_t *obst)
{
    float comp = 0;
    while (list->object->type != PLAYER) {
        list = list->next;
    }
    for (int i = 0; obst; obst = obst->next) {
        comp = list->object->position_window.x + list->object->rect.width;
        if (comp == obst->object->position_window.x
        && list->object->position_window.y == obst->object->position_window.y)
            return (1);
    }
    return (0);
}

int collision_y(list_t *list, list_t *obst)
{
    float comp = 0;
    while (list->object->type != PLAYER)
        list = list->next;
    for (int i = 0; obst; obst = obst->next) {
        comp = list->object->position_window.y + list->object->rect.height;
        if (comp >= obst->object->position_window.y
        && list->object->position_window.x + 83 >= obst->object->position_window.x
        && list->object->position_window.x <= obst->object->position_window.x + 50)
            return (1);
    }
    return (0);
}