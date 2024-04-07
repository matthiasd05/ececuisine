#include "Joeurs.h"
BITMAP *boy_chara_image = NULL;
BITMAP *girl_chara_image = NULL;
void init_character(Character *chara, int x, int y, int size, int speed) {
    chara->x = x;
    chara->y = y;
    chara->size = size;
    chara->speed = speed;
}

void move_character(Character *chara, Character *other, int key_up, int key_down, int key_left, int key_right) {
    int newX = chara->x, newY = chara->y;

    if (key[key_up]) newY -= chara->speed;
    if (key[key_down]) newY += chara->speed;
    if (key[key_left]) newX -= chara->speed;
    if (key[key_right]) newX += chara->speed;

    // Applique les limites de l'écran
    newX = MAX(195, MIN(SCREEN_W - 160 - chara->size, newX));
    newY = MAX(185, MIN(SCREEN_H - 225 - chara->size, newY));
    // Calcule les futures zones de collision
    int futureLeft1 = newX;
    int futureRight1 = newX + chara->size;
    int futureTop1 = newY;
    int futureBottom1 = newY + chara->size;

    int left2 = other->x;
    int right2 = other->x + other->size;
    int top2 = other->y;
    int bottom2 = other->y + other->size;

    // Vérifie si le mouvement prévu cause une collision
    if (!(futureRight1 <= left2 || futureLeft1 >= right2 || futureBottom1 <= top2 || futureTop1 >= bottom2)) {
        // Si c'est le cas, annule le mouvement en rétablissant les positions originales
        return;
    }

    // Met à jour la position si aucun chevauchement n'est détecté
    chara->x = newX;
    chara->y = newY;
}
void load_boy_character_sprite() {
    boy_chara_image = load_bitmap("ECE/Man_Face.bmp", NULL);
    if (!boy_chara_image) {
        allegro_message("Erreur lors du chargement de l'image du personnage.");
        exit(-1); // Sortie en cas d'erreur
    }
}

void load_girl_character_sprite() {
    girl_chara_image = load_bitmap("ECE/Girl_Face.bmp", NULL);
    if (!girl_chara_image) {
        allegro_message("Erreur lors du chargement de l'image du deuxième personnage.");
        exit(-1); // Sortie en cas d'erreur
    }
}


void draw_boy_character(BITMAP *bmp, Character *chara) {
    draw_sprite(bmp, boy_chara_image, chara->x, chara->y);
}

void draw_girl_character(BITMAP *bmp, Character *chara) {
    draw_sprite(bmp, girl_chara_image, chara->x, chara->y);
}
