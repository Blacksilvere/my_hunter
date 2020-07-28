/*
** EPITECH PROJECT, 2019
** CPool_Part2
** File description:
** int_to_str.c
*/

#include "my.h"

char *int_to_str(long long nb)
{
    long long nb_cpy = nb;
    long long zero = 0;;
    int i;
    char *nb_str;
    int a = 0;

    if (nb == 0)
        return ("0");
    for (i = 0; nb_cpy /= 10; ++i);
    nb_str = malloc(sizeof(char) * ((i + 6) * i));
    for (i = 0; nb; ++i) {
        if (nb < zero) {
            nb *= -1;
            a = 1;
        }
        nb_str[i] = nb % 10 + 48;
        nb /= 10;
    }
    if (a)
        nb_str[i++] = '-';
    nb_str[i] = '\0';
    return my_revstr(nb_str);
}