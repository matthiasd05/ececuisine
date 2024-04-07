#include "Level.h"
BITMAP *boy_chara_image_1 = NULL;
BITMAP *girl_chara_image_2 = NULL;
void draw_level_1(BITMAP *bmp) {
    load_boy_character_sprite(); // Chargement de l'image du premier personnage
    load_girl_character_sprite(); // Chargement de l'image du deuxième personnage

    Character boy_chara, girl_chara;
    init_character(&boy_chara, 195, 200, 32, 4); // Initialisation du premier personnage
    init_character(&girl_chara, 195, 325, 32, 4); // Initialisation du deuxième personnage

    while (!key[KEY_ESC]) {
        clear_to_color(bmp, makecol(255, 255, 255));
        BITMAP *background = load_bitmap("ECE/Plateau_nv1.bmp", NULL);
        blit(background, bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        move_character(&boy_chara, &girl_chara, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);
        move_character(&girl_chara, &boy_chara, KEY_W, KEY_S, KEY_A, KEY_D);

        draw_boy_character(bmp, &boy_chara); // Dessin du premier personnage
        draw_girl_character(bmp, &girl_chara); // Dessin du deuxième personnage

        blit(bmp, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(20);
    }
    destroy_bitmap(boy_chara_image_1); // Libérez l'image du premier personnage
    destroy_bitmap(girl_chara_image_2); // Libérez l'image du deuxième personnage
}


void draw_level_2(BITMAP *bmp) {
    load_boy_character_sprite(); // Chargement de l'image du premier personnage
    load_girl_character_sprite(); // Chargement de l'image du deuxième personnage

    Character boy_chara, girl_chara;
    init_character(&boy_chara, 195, 200, 32, 4); // Initialisation du premier personnage
    init_character(&girl_chara, 195, 325, 32, 4); // Initialisation du deuxième personnage

    while (!key[KEY_ESC]) {
        clear_to_color(bmp, makecol(255, 255, 255));
        BITMAP *background = load_bitmap("ECE/Plateau_nv2.bmp", NULL);
        blit(background, bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        move_character(&boy_chara, &girl_chara, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);
        move_character(&girl_chara, &boy_chara, KEY_W, KEY_S, KEY_A, KEY_D);

        draw_boy_character(bmp, &boy_chara); // Dessin du premier personnage
        draw_girl_character(bmp, &girl_chara); // Dessin du deuxième personnage

        blit(bmp, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(20);
    }
    destroy_bitmap(boy_chara_image_1); // Libérez l'image du premier personnage
    destroy_bitmap(girl_chara_image_2); // Libérez l'image du deuxième personnage
}


void draw_level_3(BITMAP *bmp) {
    load_boy_character_sprite(); // Chargement de l'image du premier personnage
    load_girl_character_sprite(); // Chargement de l'image du deuxième personnage

    Character boy_chara, girl_chara;
    init_character(&boy_chara, 195, 200, 32, 4); // Initialisation du premier personnage
    init_character(&girl_chara, 195, 325, 32, 4); // Initialisation du deuxième personnage

    while (!key[KEY_ESC]) {
        clear_to_color(bmp, makecol(255, 255, 255));
        BITMAP *background = load_bitmap("ECE/Plateau_nv3.bmp", NULL);
        blit(background, bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        move_character(&boy_chara, &girl_chara, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);
        move_character(&girl_chara, &boy_chara, KEY_W, KEY_S, KEY_A, KEY_D);

        draw_boy_character(bmp, &boy_chara); // Dessin du premier personnage
        draw_girl_character(bmp, &girl_chara); // Dessin du deuxième personnage

        blit(bmp, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(20);
    }
    destroy_bitmap(boy_chara_image_1); // Libérez l'image du premier personnage
    destroy_bitmap(girl_chara_image_2); // Libérez l'image du deuxième personnage
}