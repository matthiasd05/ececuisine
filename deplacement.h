#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <allegro.h> // Assurez-vous d'inclure Allegro ici si nécessaire

// Structure pour représenter une forme
typedef struct {
    int x; // Position en x
    int y; // Position en y
    int couleur; // Couleur de la forme
} Forme;

void deplacement(Forme *boule);

#endif // DEPLACEMENT_H
