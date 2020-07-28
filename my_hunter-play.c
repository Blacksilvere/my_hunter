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
#include"my.h"

int my_hunter_play()
{
    float vitesse = 5;
    int score = 0;
    int score1 = 0;
    int i = 0;
    float seconds2;
    float seconds;
    char* score5 = malloc(sizeof(char)*10000);

    sfVideoMode mode = {1920,1080,32};
    sfVector2f taille_enemy = {200,156};
    sfVector2f taille_DCA = {160,160};
    sfVector2f taille_vie = {160,160};
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
    sfText* score2;
    sfText* score3;
    sfText* score6;
    sfSprite* sprite;
    sfSprite* sprite_enemy;
    sfSprite* souris_sprite;
    sfFont* font;
    sfMusic* music_jeu;
    sfSound* tire;
    sfVector2f move;
    sfVector2f pos_enemy = {move.x,move.y};
    sfVector2f pos_DCA;
    sfVector2f pos_score = {1600,1000};
    sfVector2f pos_score1 = {1810,1000};
    sfVector2f pos_vie = {1720,10};
    sfVector2i mouse;
    sfVector2f mouse2;
    sfVector2i mouse3;
    sfVector2f mouse4;
    sfRectangleShape* vie;
    sfTexture* barre_vie;
    sfTexture* barre_vie1;
    sfTexture* barre_vie2;
    sfSprite* barre_de_vie;

    window_play = sfRenderWindow_create(mode,"MH_HUNTER", sfFullscreen | sfClose, NULL);
    if(!window_play)
        return EXIT_FAILURE;

    font = sfFont_createFromFile("font/arial.ttf");
    if(!font)
        return EXIT_FAILURE;

    barre_vie = sfTexture_createFromFile("texture/vie/barre_de_vie.png",NULL);
    if(!barre_vie)
        return EXIT_FAILURE;

     barre_vie1 = sfTexture_createFromFile("texture/vie/barre_de_vie1.png",NULL);
    if(!barre_vie1)
        return EXIT_FAILURE;

     barre_vie2 = sfTexture_createFromFile("texture/vie/barre_de_vie2.png",NULL);
    if(!barre_vie2)
        return EXIT_FAILURE;

    crossfire = sfTexture_createFromFile("texture/crossfire.png",NULL);
    if(!crossfire)
        return EXIT_FAILURE;   

    texture = sfTexture_createFromFile("texture/background/game.png",NULL);
    if(!texture)
        return EXIT_FAILURE;

    texture_DCA = sfTexture_createFromFile("texture/cannon/DCA.png",NULL);
    if(!texture_DCA)
        return EXIT_FAILURE;

    texture_DCA_tir3 = sfTexture_createFromFile("texture/cannon/DCA3.png",NULL);
    if(!texture_DCA_tir3)
        return EXIT_FAILURE;

    texture_enemy = sfTexture_createFromFile("texture/enemy/enemy.png",NULL);
    if(!texture_enemy)
        return EXIT_FAILURE;

    texture_enemy2 = sfTexture_createFromFile("texture/enemy/enemy2.png",NULL);
    if(!texture_enemy)
        return EXIT_FAILURE;

    tire = sfMusic_createFromFile("sound/tire.ogg");
    if(!tire)
        return EXIT_FAILURE;

    score2 = sfText_create();
    sfText_setString(score2,"SCORE :");
    sfText_setPosition(score2,pos_score);
    sfText_setFont(score2,font);
    sfText_setCharacterSize(score2, 50);

    score3 = sfText_create();
    sfText_setString(score3,score5);
    sfText_setPosition(score3,pos_score1);
    sfText_setFont(score3,font);
    sfText_setCharacterSize(score3,50);

    score6 = sfText_create();
    sfText_setString(score6,score1);
    sfText_setPosition(score6,pos_score1);
    sfText_setFont(score6,font);
    sfText_setCharacterSize(score6,50);

    vie = sfRectangleShape_create();
    sfRectangleShape_setPosition(vie,pos_vie);
    sfRectangleShape_setTexture(vie,barre_vie,sfTrue);
    sfRectangleShape_setSize(vie,taille_vie);

    enemy = sfRectangleShape_create();
    sfRectangleShape_setPosition(enemy,pos_enemy);
    sfRectangleShape_setTexture(enemy,texture_enemy,sfTrue);
    sfRectangleShape_setSize(enemy,taille_enemy);

    DCA = sfRectangleShape_create();
    sfRectangleShape_setPosition(DCA,pos_DCA);
    sfRectangleShape_setTexture(DCA,texture_DCA,sfTrue);
    sfRectangleShape_setSize(DCA,taille_DCA);


    sprite = sfSprite_create();
    sfSprite_setTexture(sprite,texture,sfTrue);

    sprite_enemy = sfSprite_create();
    sfSprite_setTexture(sprite_enemy,texture_enemy,sfTrue);

    souris_sprite = sfSprite_create();
    sfSprite_setTexture(souris_sprite,crossfire,sfTrue);

    clock = sfClock_create();

    clock2 = sfClock_create();

    sfRenderWindow_setFramerateLimit(window_play, 60);

    while(sfRenderWindow_isOpen(window_play))
    {
        mouse = sfMouse_getPositionRenderWindow(window_play);
            mouse2.x = (float)mouse.x;
            mouse2.y = (float)mouse.y;

        while (sfRenderWindow_pollEvent(window_play, &event))
        {
            if(event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyLControl) || sfKeyboard_isKeyPressed(sfKeyEscape)){
                sfRenderWindow_close(window_play);
            }

            if(event.type == sfEvtMouseButtonPressed){
                sfMusic_play(tire);
            }

            if(event.type == sfEvtMouseButtonPressed) {
                if (mouse2.x >= move.x && mouse2.x <= move.x + 200
                && mouse2.y >= move.y && mouse2.y <= move.y + 156){
                    move.x = -200;
                    move.y = rand()%800;
                    score = score + 10;
                    sfRectangleShape_setPosition(enemy,move);
                }
            }
                score5 = int_to_str(score);        
                sfText_setString(score3,score5);
                if(event.type == sfEvtMouseButtonPressed)
                    sfRectangleShape_setTexture(DCA,texture_DCA_tir3,sfTrue);
                if(event.type == sfEvtMouseButtonReleased)
                    sfRectangleShape_setTexture(DCA,texture_DCA,sfTrue);
        }
        if (score == 1000){
            sfRenderWindow_close(window_play);
            hunter();
        }

        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;

        if(move.x > 1920) {
            move.x = -250;
            move.y = rand()%800;
            i++;
            sfRectangleShape_setPosition(enemy,pos_enemy);
        }
        
        if (seconds > 0.01) {
        move.x = move.x + vitesse;
        sfRectangleShape_setPosition(enemy,move);
        sfClock_restart(clock);
        }
        time2 = sfClock_getElapsedTime(clock2);
        seconds2 = time2.microseconds / 1000000.0;

        if(seconds2 > 5){
            vitesse = vitesse + 2;
            sfClock_restart(clock2);
        }
        if(i == 1){
            sfRectangleShape_setTexture(vie,barre_vie1,sfTrue);
        }
        if(i == 2){
            sfRectangleShape_setTexture(vie,barre_vie2,sfTrue);
        }
        if(i == 3){
            sfRenderWindow_close(window_play);
            hunter();          
        }

        mouse3 = sfMouse_getPositionRenderWindow(window_play);
        mouse4.x = (float)mouse3.x - 75;
        mouse4.y = (float)mouse3.y - 75;
        
        sfSprite_setPosition(souris_sprite,mouse4);

        pos_DCA.x = mouse2.x + 100;
        pos_DCA.y = 920;

        sfRectangleShape_setPosition(DCA,pos_DCA);
        sfRenderWindow_drawSprite(window_play,sprite,NULL);
        sfRenderWindow_setMouseCursorVisible(window_play,0);
        sfRenderWindow_drawRectangleShape(window_play,DCA,NULL);
        sfRenderWindow_drawRectangleShape(window_play,enemy,NULL);
        sfRenderWindow_drawRectangleShape(window_play,vie,NULL);
        sfRenderWindow_drawText(window_play,score3,NULL);
        sfRenderWindow_drawText(window_play,score2,NULL);
        sfRenderWindow_drawSprite(window_play,souris_sprite,NULL);
        sfRenderWindow_display(window_play);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window_play);
}