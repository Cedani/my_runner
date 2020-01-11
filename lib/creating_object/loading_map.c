/*
** EPITECH PROJECT, 2019
** loading_map.c
** File description:
** loading map
*/

#include "../../include/load_map.h"
#include "../../include/list.h"

static const int offset = -1;
static const char *img = "image/background/rock.png";

void count_nbline(char *str, int *nb_line)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] == '\n')
            *nb_line += 1;
}

char **loading_map(char *filepath)
{
    int nb_line = 0;
    struct stat stat1;
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    char **map = NULL;

    stat(filepath, &stat1);
    buffer = malloc(sizeof(*buffer) * stat1.st_size + 1);
    read(fd, buffer, stat1.st_size);
    buffer[stat1.st_size] = '\0';
    count_nbline(buffer, &nb_line);
    nb_line += 1;
    map = my_str_to_word_array(buffer, nb_line);
    return (map);
}

list_t *create_list_obstacle(char **map)
{
    float pos_x = 0;
    float pos_y = 0;
    list_t *list_obst = NULL;
    game_object_t *obst = NULL;

    for (int i = 0; map[i]; i += 1) {
        pos_x = 0;
        for (int j = 0; map[i][j]; j += 1) {
            if (map[i][j] == '0') {
                obst = init_obstacle(pos_x, pos_y);
                obst->type = OBSTACLE;
                obst->plan = FRONT;
                add_element(&list_obst, obst);
            }
            pos_x += 50;
        }
        pos_y += 50;
    }
    return (list_obst);
}

game_object_t *init_obstacle(float pos_x, float pos_y)
{
    game_object_t *obst = malloc(sizeof(*obst));

    obst->position_window.x = pos_x;
    obst->position_window.y = pos_y;
    obst->velocity.x = 50;
    obst->velocity.y = 50;
    obst->offset = offset;
    obst->clock = sfClock_create();
    obst->Texture = sfTexture_createFromFile(img, NULL);
    obst->Sprite = sfSprite_create();
    sfSprite_setTexture(obst->Sprite, obst->Texture, sfFalse);
    return (obst);
}