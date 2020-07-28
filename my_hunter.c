/*
** EPITECH PROJECT, 2019
** 101graphic_pong.c
** File description:
** 101graphic_pong
*/

#include<SFML/Graphics.h>
#include<SFML/Audio.h>
#include<SFML/Config.h>
#include<SFML/System.h>
#include<stdlib.h>
#include<stdio.h>
#include"my.h"

int hunter()
{
    int i = 0;
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* texture_button;
    sfTexture* texture_sound;
    sfTexture* texture_sound_mute;
    sfTexture* texture_button_opp;
    sfTexture* crossfire;
    sfText* text_titre;
    sfText* text_button;
    sfRectangleShape* button_play;
    sfRectangleShape* button_help;
    sfRectangleShape* button_sound;
    sfEvent event;
    sfSprite* sprite;
    sfSprite* souris_sprite;
    sfFont* font;
    sfMusic* music;
    sfVector2f pos_titre = {480, 120};
    sfVector2f pos_button_play = {450, 320};
    sfVector2f pos_text_play = {550, 370};
    sfVector2f taille_button = {300,190};
    sfVector2i mouse;
    sfVector2f mouse2;
    sfVector2i mouse3;
    sfVector2f mouse4;
    sfVector2f pos_music = {0,0};
    sfVector2f taille_button_sound = {90, 100};

    window = sfRenderWindow_create(mode,"MY_HUNTER", sfResize | sfClose, NULL);
    if(!window)
        return EXIT_FAILURE;

    texture = sfTexture_createFromFile("texture/background/background.jpg",NULL);
    if(!texture)
        return EXIT_FAILURE;

    texture_button = sfTexture_createFromFile("texture/button/button.png",NULL);
    if(!texture_button)
        return EXIT_FAILURE;

    texture_sound = sfTexture_createFromFile("texture/sound.png",NULL);
    if(!texture_sound)
        return EXIT_FAILURE;
    
    texture_sound_mute = sfTexture_createFromFile("texture/sound_mute.png",NULL);
    if(!texture_sound_mute)
        return EXIT_FAILURE;

    texture_button_opp = sfTexture_createFromFile("texture/button/button_opp.png",NULL);
    if(!texture_button_opp)
        return EXIT_FAILURE;

    crossfire = sfTexture_createFromFile("texture/crossfire.png",NULL);
    if(!crossfire)
        return EXIT_FAILURE;

    font = sfFont_createFromFile("font/Antique Cherry.ttf");
    if(!font)
        return EXIT_FAILURE;
    
    music = sfMusic_createFromFile("sound/music-menu.ogg");
    if(!music)
      return EXIT_FAILURE;
    
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite,texture,sfTrue);
    
    souris_sprite = sfSprite_create();
    sfSprite_setTexture(souris_sprite,crossfire,sfTrue);

    sfRenderWindow_setFramerateLimit(window, 60);

    text_titre = sfText_create();
    sfText_setString(text_titre, "sky-hunter");
    sfText_setPosition(text_titre, pos_titre);
    sfText_setFont(text_titre, font);
    sfText_setCharacterSize(text_titre, 110);

    text_button = sfText_create();
    sfText_setString(text_button,"Play");
    sfText_setPosition(text_button, pos_text_play);
    sfText_setFont(text_button,font);
    sfText_setCharacterSize(text_button, 50);

    button_play = sfRectangleShape_create();
    sfRectangleShape_setPosition(button_play,pos_button_play);
    sfRectangleShape_setTexture(button_play,texture_button,sfTrue);
    sfRectangleShape_setSize(button_play,taille_button);

    button_sound = sfRectangleShape_create();
    sfRectangleShape_setPosition(button_sound,pos_music);
    sfRectangleShape_setTexture(button_sound,texture_sound,sfTrue);
    sfRectangleShape_setSize(button_sound,taille_button_sound);
    
    sfMusic_play(music);

    while(sfRenderWindow_isOpen(window))
    {
        
        while(sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyLControl)) {
                sfRenderWindow_close(window);
            }
                if(i == 0 && event.type == sfEvtMouseButtonPressed) {
                    if (mouse2.x >= pos_music.x && mouse2.x <= pos_music.x + 90 
                    && mouse2.y >= pos_music.y && mouse2.y <= pos_music.y + 90){
                        sfMusic_setVolume(music, 0);
                        sfRectangleShape_setTexture(button_sound,texture_sound_mute,sfTrue);
                        i++;
                    }
                }
                else
                {
                    if(i == 1 && event.type == sfEvtMouseButtonPressed) {
                        if (mouse2.x >= pos_music.x && mouse2.x <= pos_music.x + 90 
                        && mouse2.y >= pos_music.y && mouse2.y <= pos_music.y + 90){
                            sfMusic_setVolume(music, 100);
                            sfRectangleShape_setTexture(button_sound,texture_sound,sfTrue);
                            i--;
                        }
                    }
                }
                if(event.type == sfEvtMouseButtonPressed){
                    if (mouse2.x >= pos_button_play.x && mouse2.x <= pos_button_play.x + 300
                    && mouse2.y >= pos_button_play.y && mouse2.y <= pos_button_play.y + 190) {
                        sfRenderWindow_close(window);
                        sfMusic_stop(music);
                        my_hunter_play();
                    }
                }
        }
        if (mouse2.x >= pos_button_play.x && mouse2.x <= pos_button_play.x + 300
        && mouse2.y >= pos_button_play.y && mouse2.y <= pos_button_play.y + 130) {
            sfRectangleShape_setTexture(button_play,texture_button_opp,sfTrue);
        }
        else {
        sfRectangleShape_setTexture(button_play,texture_button,sfTrue);
        }
        mouse3 = sfMouse_getPositionRenderWindow(window);
        mouse4.x = (float)mouse3.x - 75;
        mouse4.y = (float)mouse3.y - 75;

        mouse = sfMouse_getPositionRenderWindow(window);
        mouse2.x = (float)mouse.x;
        mouse2.y = (float)mouse.y;
        sfSprite_setPosition(souris_sprite,mouse4);
        sfRenderWindow_setMouseCursorVisible(window,0);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite,NULL);
        sfRenderWindow_drawRectangleShape(window, button_play, NULL);
        sfRenderWindow_drawRectangleShape(window,button_sound,NULL);
        sfRenderWindow_drawText(window, text_titre, NULL);
        sfRenderWindow_drawText(window, text_button, NULL);
        sfRenderWindow_drawSprite(window,souris_sprite,NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfText_destroy(text_button);
    sfRectangleShape_destroy(button_play);
    sfRectangleShape_destroy(button_sound);
    sfRenderWindow_destroy(window);
    sfText_destroy(text_titre);
    return EXIT_SUCCESS;
}