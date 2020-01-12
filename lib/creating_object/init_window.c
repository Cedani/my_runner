/*
** EPITECH PROJECT, 2020
** init_window.c
** File description:
** initialisation of windows parameter
*/

#include "../../include/list.h"

res_t *initialize_parameter(char *filepath)
{
    res_t *res = malloc(sizeof(*res));
    res->list = init_list();
    res->map = loading_map(filepath);
    res->obst = create_list_obstacle(res->map);

    res->window = create_window();
    res->obj = create_button();
    res->clock = sfClock_create();
    create_score(res);
    sfRenderWindow_setFramerateLimit(res->window, 80);
    return (res);
}

int event_scene_game(res_t *res)
{
    if (res->scene == 0)
        display_menu(res->obj, res->window);
    else if (res->scene == 1)
        actualise_window(res, res->list, res->obst);
    if (collision_y(res->list, res->obst) == 1 && res->scene != 2)
        highscore(res);
    if (res->scene == 2)
        display_losing(res);
    if (res->score_int == 400)
        res->scene = 3;
    if (res->scene == 3)
        display_winning(res);
    return (0);
}

void destroy_map(char **map)
{
    for (int i = 0; map[i]; i += 1)
        free(map[i]);
    free(map);
}

void destroy_res(res_t *res)
{
    for (; res->list; res->list = res->list->next) {
        sfClock_destroy(res->list->object->clock);
        sfSprite_destroy(res->list->object->Sprite);
        sfTexture_destroy(res->list->object->Texture);
    }
    for (; res->obst; res->obst = res->obst->next) {
        sfClock_destroy(res->obst->object->clock);
        sfSprite_destroy(res->obst->object->Sprite);
        sfTexture_destroy(res->obst->object->Texture);
    }
    sfClock_destroy(res->obj->clock);
    sfSprite_destroy(res->obj->Sprite);
    sfTexture_destroy(res->obj->Texture);
    sfClock_destroy(res->clock);
    sfFont_destroy(res->font);
    destroy_map(res->map);
    sfText_destroy(res->text1);
    sfText_destroy(res->score);
    sfRenderWindow_destroy(res->window);
}
