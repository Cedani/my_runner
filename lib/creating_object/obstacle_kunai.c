/*
** EPITECH PROJECT, 2020
** kunai obstacle
** File description:
** kunai
*/

#include "../../include/list.h"

static const char *filepath = "image/sprite/enemy/Kunai_test.png";

list_t *create_kunai(char **map)
{
    float pos_x = 0;
    float pos_y = 0;
    list_t *kunai = NULL;
    game_object_t *enem = NULL;

    for (int i = 0; map[i]; i += 1) {
        pos_x = 0;
        for (int j = 0; map[i][j]; j += 1) {
            if (map[i][j] == '1') {
                enem = init_kunai(pos_x, pos_y);
                enem->type = OBSTACLE;
                enem->plan = FRONT;
                add_element(&kunai, enem);
            }
            pos_x += 50;
        }
        pos_y += 50;
    }
    return (kunai);
}

game_object_t *init_kunai(float pos_x, float pos_y)
{
    game_object_t *kunai = malloc(sizeof(*kunai));

    kunai->position_window.x = pos_x;
    kunai->position_window.y = pos_y;
    kunai->time_offset = 0.01;
    kunai->velocity.x = 50;
    kunai->velocity.y = 50;
    kunai->offset = -1;
    kunai->clock = sfClock_create();
    kunai->Texture = sfTexture_createFromFile(filepath, NULL);
    kunai->Sprite = sfSprite_create();
    sfSprite_setTexture(kunai->Sprite, kunai->Texture, sfFalse);
    return (kunai);
}