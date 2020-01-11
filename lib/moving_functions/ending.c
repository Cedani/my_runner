/*
** EPITECH PROJECT, 2020
** ending.c
** File description:
** ending page
*/

#include "../../include/list.h"

static const char *filepath = "image/background/lose.png";
static const char *win = "image/background/win.png";

void display_losing(res_t *res)
{
    sfText *lose_text = sfText_create();
    sfVector2f pos;
    pos.x = 400;
    pos.y = 300;
    res->obj->Texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(res->obj->Sprite, res->obj->Texture, sfTrue);
    res->obj->position_window.x = 0.0;
    res->obj->position_window.y = 0.0;
    sfText_setPosition(lose_text, pos);
    sfText_setFont(lose_text, res->font);
    sfText_setString(lose_text, "LOOSER");
    sfText_setCharacterSize(lose_text, 50);
    sfText_setColor(lose_text, sfWhite);
    sfSprite_setPosition(res->obj->Sprite, res->obj->position_window);
    sfRenderWindow_drawSprite(res->window, res->obj->Sprite, NULL);
    display_score(res);
    sfRenderWindow_drawText(res->window, lose_text, NULL);
    sfRenderWindow_display(res->window);
}

void display_winning(res_t *res)
{
    sfText *win_text = sfText_create();
    sfVector2f pos;
    pos.x = 400;
    pos.y = 300;
    res->obj->Texture = sfTexture_createFromFile(win, NULL);
    sfSprite_setTexture(res->obj->Sprite, res->obj->Texture, sfTrue);
    res->obj->position_window.x = 0.0;
    res->obj->position_window.y = 0.0;
    sfText_setPosition(win_text, pos);
    sfText_setFont(win_text, res->font);
    sfText_setString(win_text, "YOU NAILED IT");
    sfText_setCharacterSize(win_text, 50);
    sfText_setColor(win_text, sfGreen);
    sfSprite_setPosition(res->obj->Sprite, res->obj->position_window);
    sfRenderWindow_drawSprite(res->window, res->obj->Sprite, NULL);
    display_score(res);
    sfRenderWindow_drawText(res->window, win_text, NULL);
    sfRenderWindow_display(res->window);
}