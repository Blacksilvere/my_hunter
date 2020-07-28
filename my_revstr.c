/*
** EPITECH PROJECT, 2019
** le juez
** File description:
** my revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    char *dest = malloc(sizeof(char)*my_strlen(str) + 1);
    int i = 0;
    int y = my_strlen(str) - 1;
    while(i != my_strlen(str)){
    dest[i] = str[y];
    i++;
    y--;
    }
    dest[i] = '\0';
    return dest;
}
