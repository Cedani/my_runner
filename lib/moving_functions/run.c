/*
** EPITECH PROJECT, 2019
** run c
** File description:
** running sprite
*/

#include "../../include/list.h"

void move_background(game_object_t *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds > 0.05) {
        if (obj->position_window.x <= obj->max_value)
            obj->position_window.x = 0;
        else
            obj->position_window.x += obj->offset;
        sfClock_restart(obj->clock);
    }
    sfSprite_setPosition(obj->Sprite, obj->position_window);
}

void move_plan(list_t *list, sfRenderWindow *window)
{
    while (list) {
        if (list->object->type == BACK) {
            move_background(list->object);
            sfRenderWindow_drawSprite(window, list->object->Sprite, NULL);
        }
        list = list->next;
    }
}

void actualise_obstacle(list_t *list, sfRenderWindow *window)
{
    for (; list; list = list->next) {
        draw_obstacle(list->object);
        sfRenderWindow_drawSprite(window, list->object->Sprite, NULL);
    }
}

void draw_obstacle(game_object_t *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds > obj->time_offset) {
        obj->position_window.x += obj->offset;
        sfClock_restart(obj->clock);
    }
    if (obj->position_window.x <= -50)
        obj->position_window.x = 800;
    sfSprite_setPosition(obj->Sprite, obj->position_window);
}