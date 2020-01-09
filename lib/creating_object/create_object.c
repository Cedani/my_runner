/*
** EPITECH PROJECT, 2019
** create_object.c
** File description:
** create object
*/

#include "../../include/list.h"

static const char *filepath[NB_ELEMENT] = {
    "image/sprite/player/run.png",
    "image/background/BACK_test.png",
    "image/background/FRONT_test.png",
};

static const char *path_jump = "image/sprite/player/jump.png";

static const sfVector2f ini_pos[NB_ELEMENT] = {
    {0, 450},
    {0, 0},
    {0, 0}
};

void init_object(game_object__t *obj, ENUM plan, TYPE type)
{
    static int index = 0;
    if (type == PLAYER)
        init_player(obj, filepath[index], ini_pos[index]);
    else if (type == BACK)
        init_background(obj, filepath[index], ini_pos[index], plan);
    obj->type = type;
    index += 1;
}

void init_player(game_object__t *pla, char const *filepath, sfVector2f pos)
{
    pla->offset = 83;
    init_rect_player(&pla->rect);
    pla->Texture = sfTexture_createFromFile(filepath, NULL);
    pla->Texture_jump = sfTexture_createFromFile(path_jump, NULL);
    pla->Sprite = sfSprite_create();
    sfSprite_setTexture(pla->Sprite, pla->Texture, sfTrue);
    pla->max_value = 498;
    pla->position_window = pos;
    pla->plan = FRONT;
    pla->clock = sfClock_create();
    pla->velocity.x = 0;
    pla->velocity.y = 0;
}

void init_enemy(game_object__t *ene, char const *filepath, sfVector2f pos)
{
}

void init_background(game_object__t *b, char const *path, sfVector2f p, ENUM pl)
{
    b->clock = sfClock_create();
    if (pl == FRONT)
        b->offset = -8;
    else
        b->offset = -2;
    b->plan = pl;
    b->max_value = -800;
    b->position_window = p;
    b->Sprite = sfSprite_create();
    b->Texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(b->Sprite, b->Texture, sfTrue);
}