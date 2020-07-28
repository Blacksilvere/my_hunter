 /*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

 #include<unistd.h>
 #include"my.h"

 int my_putchar(char c)
{
    write(1, &c, 1);
}


