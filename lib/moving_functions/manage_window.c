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
        if (res->event.key.code == sfKeySpace && list->object->jump == 0)
            list->object->velocity.y = -35;
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
    actualize_displaying(res, list, obst);
}