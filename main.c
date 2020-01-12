/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "./include/list.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        my_runner("test");
        return (0);
    }
    if (parsing(argv) == 84)
        return (84);
    return (0);
}