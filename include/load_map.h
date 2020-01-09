/*
** EPITECH PROJECT, 2019
** load_map.h
** File description:
** map's loading useful function
*/

#ifndef MAP
#define MAP
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char **my_str_to_word_array(char *, int);
#endif /* !MAP */