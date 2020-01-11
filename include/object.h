/*
** EPITECH PROJECT, 2019
** object.h
** File description:
** object.h
*/

#ifndef OBJECT
#define OBJECT
#define TEST_WIDTH  800
#define TEST_HEIGHT  600
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    FRONT,
    MIDDLE,
    BACK,
}ENUM;

typedef enum {
    PLAYER,
    ENEMY,
    BACKGROUND,
    OBSTACLE
}TYPE;

typedef struct game_object_s {
    sfIntRect rect;
    sfSprite *Sprite;
    sfTexture *Texture;
    int offset;
    int max_value;
    sfVector2f position_window;
    sfVector2f velocity;
    sfClock *clock;
    float seconds;
    sfTime time;
    ENUM plan;
    TYPE type;
    float init_pos;
}game_object_t;

typedef struct obstacle_s {
    sfSprite *Sprite;
    sfTexture *Texture;
    int width;
    int height;
    sfVector2f pos;
} obstacle_t;

void init_rect_player(sfIntRect *);
void init_rect_jump(sfIntRect *);
void init_object(game_object_t *, ENUM, TYPE);
void init_player(game_object_t *, char const *, sfVector2f);
void init_enemy(game_object_t *, char const *, sfVector2f);
void init_background(game_object_t *, char const *, sfVector2f, ENUM);
void move_rect(sfIntRect *, int, int);
void my_runner(char *filepath);
#endif /* !OBJECT */
