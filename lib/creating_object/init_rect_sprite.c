/*
** EPITECH PROJECT, 2019
** ini_rect_sprite.c
** File description:
** initialisation of sprite's rect
*/

#include "../../include/list.h"

void init_rect_player(sfIntRect *rect)
{
    rect->left = 0;
    rect->top = 0;
    rect->width = 83;
    rect->height = 55;
}

void init_rect_jump(sfIntRect *rect)
{
    rect->left = 0;
    rect->top = 0;
    rect->width = 77;
    rect->height = 36;
}
