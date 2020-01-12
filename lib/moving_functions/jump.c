/*
** EPITECH PROJECT, 2019
** jump
** File description:
** jump
*/

#include "../../include/list.h"

void jump_moving(res_t *res, list_t *list, list_t *obst)
{
    list->object->time = sfClock_getElapsedTime(list->object->clock);
    list->object->seconds = list->object->time.microseconds / 1000000.0;
    if (list->object->seconds > 0.1) {
        list->object->position_window.y += list->object->velocity.y;
        if (list->object->position_window.y < 450) {
            list->object->velocity.y += 2.5;
            list->object->jump = -1;
            if (list->object->position_window.y <= 350)
                list->object->position_window.y = 350;
        } else {
            list->object->position_window.y = 450;
            list->object->jump = 0;
            list->object->velocity.y = 0;
        }
        move_rect(&list->object->rect, list->object->offset,
                    list->object->max_value);
        res->score_int += 1;
        sfClock_restart(list->object->clock);
    }
}

void increase_time(res_t *res, list_t *obst)
{
    for (; obst; obst = obst->next)
        if (res->score_int > 0 && res->score_int % 50 == 0)
            obst->object->time_offset -= 0.000005;
}

void actualize_displaying(res_t *res, list_t *list, list_t *obst)
{
    move_plan(list, res->window);
    jump_moving(res, list, obst);
    increase_time(res, obst);
    actualise_obstacle(obst, res->window);
    sfSprite_setTextureRect(list->object->Sprite, list->object->rect);
    sfSprite_setPosition(list->object->Sprite, list->object->position_window);
    sfRenderWindow_drawSprite(res->window, list->object->Sprite, NULL);
    display_score(res);
    sfRenderWindow_display(res->window);
}
