/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** menu
*/

#include "../../include/list.h"

static const char *filepath = "image/sprite/player/menu_button.png";

game_object_t *create_button(void)
{
    game_object_t *obj = malloc(sizeof(*obj));
    obj->Texture = sfTexture_createFromFile(filepath, NULL);
    obj->Sprite = sfSprite_create();
    sfSprite_setTexture(obj->Sprite, obj->Texture, sfTrue);
    obj->position_window.x = 0.0;
    obj->position_window.y = 0.0;

    return (obj);
}

void display_menu(game_object_t *obj, sfRenderWindow *window)
{
    sfSprite_setPosition(obj->Sprite, obj->position_window);
    sfRenderWindow_drawSprite(window, obj->Sprite, NULL);
    sfRenderWindow_display(window);
}

void analyse_event_mouse(res_t *res, sfMouseButtonEvent button)
{
    if ((button.x >= 210 && button.x <= 580  && res->score_int == 0)
        && (button.y >= 405 && button.y <= 495))
            res->scene = 1;
    else if (res->score_int == 0)
        res->scene = 0;
}