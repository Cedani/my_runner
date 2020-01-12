/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** prototype of linked list function
*/

#ifndef LIST
#define LIST
#include "object.h"
#define NB_ELEMENT  4

typedef struct list_s {
    game_object_t *object;
    struct list_s *next;
} list_t;

typedef struct list_obst_s {
    obstacle_t *obstacle;
    struct list_obst_s *next;
} list_obst_t;

typedef struct res_s {
    sfEvent event;
    sfRenderWindow *window;
    game_object_t *obj;
    int scene;
    sfText *score;
    sfText *text1;
    sfFont *font;
    sfVector2f pos_score;
    int score_int;
    sfClock *clock;
    sfVector2f pos_int;
    char **map;
    list_t *list;
    list_t *obst;
} res_t;

void add_element(list_t **, game_object_t *);
void display_score(res_t *res);
void remove_element(list_t **, int);
void insert_element(list_t **, int, game_object_t *);
list_t *init_list(void);
void analyse_window_envent(res_t *, list_t *, list_t *);
void move_plan(list_t *, sfRenderWindow *);
list_t *create_list_obstacle(char **);
game_object_t *init_obstacle(float, float);
char **loading_map(char *);
void actualise_window(res_t *, list_t *, list_t *);
void actualise_obstacle(list_t *, sfRenderWindow *);
void draw_obstacle(game_object_t *);
int my_strlen(char const *);
void free_all(list_t **);
int collision_x(list_t *, list_t *);
int collision_y(list_t *, list_t *);
game_object_t *create_button(void);
void analyse_event_mouse(res_t *res, sfMouseButtonEvent button);
void display_menu(game_object_t *obj, sfRenderWindow *window);
void create_score(res_t *res);
res_t *initialize_parameter(char *filepath);
int event_scene_game(res_t *res);
sfRenderWindow *create_window(void);
void destroy_res(res_t *res);
void display_losing(res_t *res);
void display_winning(res_t *res);
void actualize_displaying(res_t *res, list_t *list, list_t *obst);
void jump_moving(res_t *res, list_t *list, list_t *obst);
int attrib_sign(char const *str, int i);
int attrib_num(char const *str, int i);
int my_getnbr(char const *str);
char *my_itoa(int i);
void highscore(res_t *res);
int parsing(char **argv);
#endif /* !LIST */
