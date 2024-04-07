
#ifndef ECECOOK_JOEURS_H
#define ECECOOK_JOEURS_H
#include "BUFFER.h"
typedef struct {
    int x, y;
    int size;
    int speed;
} Character;
void init_character(Character *chara, int x, int y, int size, int speed);
void move_character(Character *chara, Character *other, int key_up, int key_down, int key_left, int key_right);
void load_boy_character_sprite();
void load_girl_character_sprite();
void draw_boy_character(BITMAP *bmp, Character *chara);
void draw_girl_character(BITMAP *bmp, Character *chara);
#endif
