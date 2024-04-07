#ifndef ECECOOK_BUFFER_H
#define ECECOOK_BUFFER_H

#include <allegro.h>
#include <stdio.h>
#define SCREEN_W 800
#define SCREEN_H 600

BITMAP *buffer;  // Bitmap pour le double buffering
void init();
void deinit();
#endif //ECECOOK_BUFFER_H
