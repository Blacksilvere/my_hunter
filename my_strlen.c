/*
** EPITECH PROJECT, 2019
** strlen
** File description:
** strlzn
*/

int my_strlen(char const *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
