/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/
#include<unistd.h>
#include"my.h"

int my_putstr(char *str)
{
    int j;

    j = 0;
    while (str[j] != '\0') {
        my_putchar(str[j]);
        j++;
    }
}

