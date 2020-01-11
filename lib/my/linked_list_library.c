/*
** EPITECH PROJECT, 2019
** linked_list_library
** File description:
** library of linked list
*/

#include "../../include/list.h"

static const ENUM order[NB_ELEMENT] = {
    FRONT,
    BACK,
    MIDDLE,
    FRONT
};

static const TYPE order_creating[NB_ELEMENT] = {
    PLAYER,
    BACK,
    BACK,
    BACK
};

void add_element(list_t **list, game_object_t *obj)
{
    list_t *elem = malloc(sizeof(*elem));
    list_t *tmp = *list;

    elem->object = obj;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = elem;
}

void remove_element(list_t **list, int position)
{
    list_t *tmp1 = NULL;
    list_t *tmp2 = (*list);
    list_t *tmp_to_free = NULL;

    if (position == 1) {
        tmp1 = (*list);
        *list = (*list)->next;
        free(tmp1);
        return;
    }
    for (int i = 0; i < position - 2; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1 = tmp2->next->next;
    tmp_to_free = tmp2->next;
    tmp2->next = tmp1;
    free(tmp_to_free);
}

void insert_element(list_t **list, int position, game_object_t *obj)
{
    list_t *elem = malloc(sizeof(*elem));
    list_t *tmp1 = (*list);
    list_t *tmp2 = (*list);
    elem->object = obj;

    if (position == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1->next = elem;
    elem->next = tmp2;
}

list_t *init_list(void)
{
    game_object_t *obj = NULL;
    list_t *list = NULL;

    for (int i = 1; i <= NB_ELEMENT; i += 1) {
        obj = malloc(sizeof(*obj));
        init_object(obj, order[i - 1], order_creating[i - 1]);
        add_element(&list, obj);
    }
    return (list);
}