#include "deplacement.h"

void deplacement(Forme *boule) {
    if (key[KEY_UP]) boule->y -= 5;
    if (key[KEY_DOWN]) boule->y += 5;
    if (key[KEY_LEFT]) boule->x -= 5;
    if (key[KEY_RIGHT]) boule->x += 5;

    // Déplacer la boule en diagonale (combinaison de touches)
    if (key[KEY_UP] && key[KEY_LEFT]) { // Diagonale haut-gauche
        boule->y -= 5;
        boule->x -= 5;
    }
    if (key[KEY_UP] && key[KEY_RIGHT]) { // Diagonale haut-droite
        boule->y -= 5;
        boule->x += 5;
    }
    if (key[KEY_DOWN] && key[KEY_LEFT]) { // Diagonale bas-gauche
        boule->y += 5;
        boule->x -= 5;
    }
    if (key[KEY_DOWN] && key[KEY_RIGHT]) { // Diagonale bas-droite
        boule->y += 5;
        boule->x += 5;
    }
}
