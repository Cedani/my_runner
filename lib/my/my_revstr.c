/*
** EPITECH PROJECT, 2019
** CPool_Day05
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int m = 0;
    char c = '0';

    for (; str[i]; i += 1);
    m = i - 1;
    while (j <= m) {
        c = str[j];
        str[j] = str[m];
        str[m] = c;
        j++;
        m--;
    }
    return (str);
}
