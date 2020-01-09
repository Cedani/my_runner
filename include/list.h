/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** prototype of linked list function
*/

#ifndef LIST
#define LIST
#include "object.h"
#define NB_ELEMENT  3

typedef struct list_s {
    game_object__t *object;
    struct list_s *next;
} list_t;

typedef struct list_obst_s {
    obstacle_t *obstacle;
    struct list_obst_s *next;
} list_obst_t;

void add_element(list_t **, game_object__t *);
void remove_element(list_t **, int);
void insert_element(list_t **, int, game_object__t *);
list_t *init_list(void);
void analyse_window_envent(sfRenderWindow *, sfEvent, list_t *);
void move_plan(list_t *, sfRenderWindow *);
list_t *create_list_obstacle(char **map);
game_object__t *init_obstacle(float pos_x, float pos_y);
char **loading_map(char *filepath);
void actualise_window(sfRenderWindow *window, list_t *list, list_t *obst);
void actualise_obstacle(list_t *list, sfRenderWindow *window);
void draw_obstacle(game_object__t *obj);
int my_strlen(char const *str);
void free_all(list_t **list);
int collision_x(list_t *list, list_t *obst);
int collision_y(list_t *list, list_t *obst);
#endif /* !LIST */
