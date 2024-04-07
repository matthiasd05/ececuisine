#ifndef ECECOOK_OBJECT_H
#define ECECOOK_OBJECT_H
#include "BUFFER.h"
typedef struct {
    BITMAP *image; // Pointeur vers l'image chargée
    int x;         // Position X pour afficher l'image
    int y;         // Position Y pour afficher l'image
} GeneratedImage;
void init_generated_image(GeneratedImage *genImage, const char *image_path, int x, int y);
void display_generated_image(BITMAP *bmp, GeneratedImage *genImage);
void destroy_generated_image(GeneratedImage *genImage);
#endif
