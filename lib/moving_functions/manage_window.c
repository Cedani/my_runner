/*
** EPITECH PROJECT, 2019
** manage_window
** File description:
** manage window ressources
*/

#include "../../include/list.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode;

    mode.width = TEST_WIDTH;
    mode.height = TEST_HEIGHT;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "Runner", sfDefaultStyle, NULL);
    return (window);
}

void my_runner(char *filepath)
{
    res_t *res = initialize_parameter(filepath);

    while (sfRenderWindow_isOpen(res->window)) {
        sfRenderWindow_clear(res->window, sfWhite);
        if (sfRenderWindow_pollEvent(res->window, &res->event)) {
            analyse_window_envent(res, res->list, res->obst);
        }
        event_scene_game(res);
    }
    destroy_res(res);
}

void analyse_window_envent(res_t *res, list_t *list, list_t *obst)
{
    while (list->object->type != PLAYER)
        list = list->next;
    if (res->event.type == sfEvtMouseButtonPressed)
        analyse_event_mouse(res, res->event.mouseButton);
    if (res->event.type == sfEvtClosed)
        sfRenderWindow_close(res->window);
    if (res->event.type == sfEvtKeyPressed) {
        if (res->event.key.code == sfKeySpace)
            list->object->velocity.y = -25;
        if (res->event.key.code == sfKeyEscape)
            sfRenderWindow_close(res->window);
    }
}

void move_rect(sfIntRect *rect, int offset, int max)
{
    rect->left = (rect->left + offset) % max;
}

void actualise_window(res_t *res, list_t *list, list_t *obst)
{
    while (list->object->type != PLAYER) {
        list = list->next;
    }
    list->object->time = sfClock_getElapsedTime(list->object->clock);
    list->object->seconds = list->object->time.microseconds / 1000000.0;
    move_plan(list, res->window);
    if (list->object->seconds > 0.1) {
        list->object->position_window.y += list->object->velocity.y;
        if (list->object->position_window.y <= 450) {
            list->object->velocity.y += 5;
            if (list->object->position_window.y <= 380)
                list->object->position_window.y = 380;
        } else {
            list->object->position_window.y = 450;
            list->object->velocity.y = 0;
        }
        move_rect(&list->object->rect, list->object->offset,
                    list->object->max_value);
        res->score_int += 1;
        sfClock_restart(list->object->clock);
    }
    actualise_obstacle(obst, res->window);
    sfSprite_setTextureRect(list->object->Sprite, list->object->rect);
    sfSprite_setPosition(list->object->Sprite, list->object->position_window);
    sfRenderWindow_drawSprite(res->window, list->object->Sprite, NULL);
    display_score(res);
    sfRenderWindow_display(res->window);
}