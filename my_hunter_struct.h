/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** my_hunter-play.c
*/

#include<SFML/Graphics.h>
#include<SFML/Audio.h>
#include<SFML/Config.h>
#include<SFML/System.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct declaration
{
    float vitesse;
    int score;
    int i;
    float seconds2;
    float seconds;
    sfRenderWindow* window_play;
    sfEvent event;
    sfRectangleShape* enemy;
    sfRectangleShape* DCA;
    sfClock *clock;
    sfClock *clock2;
    sfTime time;
    sfTime time2;
    sfTexture* texture;
    sfTexture* texture_DCA;
    sfTexture* texture_DCA_tir3;
    sfTexture* texture_enemy;
    sfTexture* texture_enemy2;
    sfTexture* crossfire;
    sfTexture* barre_de_vie_vide;
    sfTexture* barre_de_vie_plein;
    sfSprite* sprite;
    sfSprite* sprite_enemy;
    sfSprite* souris_sprite;
    sfFont* font;
    sfMusic* music_jeu;
    sfVector2f move;
    sfVector2f pos_DCA;
    sfVector2f pos_enemy;
    sfVector2f taille_enemy;
    sfVector2f taille_DCA;
    sfVector2i mouse;
    sfVector2f mouse2;
    sfVector2i mouse3;
    sfVector2f mouse4;
}t_decla;
