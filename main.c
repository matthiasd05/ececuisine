#include "deplacement.h"

int main() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

    Forme boule;
    boule.x = 400; // Position initiale en x
    boule.y = 300; // Position initiale en y
    boule.couleur = makecol(255, 255, 255); // Couleur blanche

    while (!key[KEY_ESC]) {
        clear_to_color(screen, makecol(0, 0, 0)); // Effacer l'écran à chaque boucle

        // Dessiner la boule à sa position actuelle
        circlefill(screen, boule.x, boule.y, 10, boule.couleur);

        // Appeler la fonction de déplacement
        deplacement(&boule);

        rest(10); // Délai pour limiter la vitesse de rafraîchissement de l'écran
    }

    allegro_exit();
    return 0; // jaime pas mathias car il a une petite gueule 
}
