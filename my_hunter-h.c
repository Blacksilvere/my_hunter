/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** my_hunter-h.c
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int fs_open_file(char const *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size + 1;
    char* file = malloc(sizeof(char)*(size));
    int fd = open(filepath,O_RDONLY);
    read(fd,file,size);
    return file;
}
int main(int ac, char **av)
{
    if(ac == 1){
        hunter();
    }
    if(av[1][0] == '-' && av[1][1] == 'h'){
    char *file = fs_open_file("h.txt");
    my_putstr(file);
    }
}