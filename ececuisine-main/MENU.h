//
// Created by abder on 19/03/2024.
//

#ifndef ECECOOK_MENU_H
#define ECECOOK_MENU_H

#define OPTION_PLAY 1
#define OPTION_LOAD 2
#define OPTION_RULES 3

#include "BUFFER.h"
#include "Level.h"

char user1[20];
char user2[20];
int user1_char_pos;
int user2_char_pos;
int current_user; // 1 ou 2 pour l'entrée des noms, 3 pour la sélection du niveau, 4 pour bloquer l'entrée
int level; // Variable pour stocker le niveau sélectionné


void draw_menu(BITMAP *bmp);
int menu_select();
void draw_text_box(BITMAP *bmp, int x, int y, const char *text, int highlight);
void draw_level_selection(BITMAP *bmp);
void draw_play_menu(BITMAP *bmp);
int select_level();

#endif //ECECOOK_MENU_H
