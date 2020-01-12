/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** display -h
*/

#include "../../include/list.h"

void writing_help(void)
{
    write(1, "Finite runner created with CSFML.\n\n", 35);
    write(1, "USAGE\n\t./my_runner map\n", 23);
    write(1, "OPTIONS\n-i\t launch the game in infinity mode.\n", 46);
    write(1, "-h\t print the usage and quit.\n\n", 31);
    write(1, "USER INTERACTIONS\n", 18);
    write(1, "SPACE_KEY\t jump\n", 16);
}

int parsing(char **argv)
{
    int fd = 0;

    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        writing_help();
        return (0);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'i') {
        my_runner("test");
        return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (84);
    close (fd);
    my_runner(argv[1]);
}