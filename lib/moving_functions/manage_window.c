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
    sfRenderWindow *window = create_window();
    sfEvent event;
    list_t *list = init_list();
    char **map = loading_map(filepath);
    list_t *obst = create_list_obstacle(map);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (sfRenderWindow_pollEvent(window, &event)) {
            analyse_window_envent(window, event, list);
        }
        if (collision_x(list, obst) == 0)
            exit(1);
        else if (collision_y(list, obst) ==  0)
            exit(1);
        else
            actualise_window(window, list, obst);
    }
    free_all(&list);
    free_all(&obst);
    sfRenderWindow_destroy(window);
}

void analyse_window_envent(sfRenderWindow *window, sfEvent event, list_t *list)
{
    while (list->object->type != PLAYER)
        list = list->next;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeySpace) {
            list->object->velocity.y = -25;
        }
    }

}

void move_rect(sfIntRect *rect, int offset, int max)
{
    rect->left = (rect->left + offset) % max;
}

void actualise_window(sfRenderWindow *window, list_t *list, list_t *obst)
{
    while (list->object->type != PLAYER) {
        list = list->next;
    }
    list->object->time = sfClock_getElapsedTime(list->object->clock);
    list->object->seconds = list->object->time.microseconds / 1000000.0;
    move_plan(list, window);
    if (list->object->seconds > 0.1) {
        list->object->position_window.y += list->object->velocity.y;
        if (list->object->position_window.y <= 450) {
            list->object->velocity.y += 5;
        } else {
            list->object->position_window.y = 450;
            list->object->velocity.y = 0;
        }
        move_rect(&list->object->rect, list->object->offset,
                    list->object->max_value);
        sfClock_restart(list->object->clock);
    }
    actualise_obstacle(obst, window);
    sfSprite_setTextureRect(list->object->Sprite, list->object->rect);
    sfSprite_setPosition(list->object->Sprite, list->object->position_window);
    sfRenderWindow_drawSprite(window, list->object->Sprite, NULL);
    sfRenderWindow_display(window);
}