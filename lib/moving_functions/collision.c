/*
** EPITECH PROJECT, 2020
** collision.c
** File description:
** collision.c
*/

#include "../../include/list.h"

int collision_x(list_t *list, list_t *obst)
{
    while (list->object->type != PLAYER) {
        list = list->next;
    }
    for (int i = 0; obst; obst = obst->next) {
        int comp = list->object->position_window.x - obst->object->position_window.x;
        printf("pla x = %lf\nobst = %lf\n", list->object->position_window.x, obst->object->position_window.x);
        if (comp == 0)
            return (1);
    }
    return (0);
}

int collision_y(list_t *list, list_t *obst)
{
    while (list->object->type != PLAYER)
        list = list->next;
    for (int i = 0; obst; obst = obst->next) {
        int comp = list->object->position_window.y - obst->object->position_window.y;
        printf("pla y = %lf\nobst = %lf\n", list->object->position_window.y, obst->object->position_window.y);
        if (comp == 0)
            return (1);
    }
    return (0);
}