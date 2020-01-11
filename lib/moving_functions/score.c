/*
** EPITECH PROJECT, 2020
** score.c
** File description:
** score
*/
#include "../../include/load_map.h"
#include "../../include/list.h"

static const char *filepath = "font/BebasNeue-Regular.ttf";

char *my_itoa(int i)
{
    int tmp = i;
    int nb_dig = 0;
    char *number = NULL;
    int k = 0;

    for (; tmp >= 1; nb_dig += 1)
        tmp /= 10;
    number = malloc(sizeof(*number) * nb_dig + 1);
    for (; i >= 1; i /= 10) {
        number[k] = i % 10 + 48;
        k += 1;
    }
    number[k] = '\0';
    number = my_revstr(number);
    return (number);
}

void display_score(res_t *res)
{
    sfText_setPosition(res->text1, res->pos_score);
    sfText_setFont(res->text1, res->font);
    sfText_setString(res->text1, "Score = ");
    sfText_setCharacterSize(res->text1, 50);
    sfText_setColor(res->text1, sfWhite);
    sfText_setPosition(res->score, res->pos_int);
    sfText_setFont(res->score, res->font);
    sfText_setString(res->score, my_itoa(res->score_int));
    sfText_setCharacterSize(res->score, 50);
    sfText_setColor(res->score, sfWhite);
    sfRenderWindow_drawText(res->window, res->score, NULL);
    sfRenderWindow_drawText(res->window, res->text1, NULL);
}

void create_score(res_t *res)
{
    res->text1 = sfText_create();
    res->pos_score.x = 300;
    res->pos_score.y = 0;
    res->font = sfFont_createFromFile(filepath);
    res->score = sfText_create();
    res->pos_score.x = 300;
    res->pos_score.y = 0;
    res->score_int = 0;
    res->pos_int.x = 430;
    res->pos_int.y = 0;
}