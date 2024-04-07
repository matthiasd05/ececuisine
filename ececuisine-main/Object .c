#include "Object .h"

// Fonction pour initialiser et charger l'image
void init_generated_image(GeneratedImage *genImage, const char *image_path, int x, int y) {
    genImage->image = load_bitmap(image_path, NULL);
    if (!genImage->image) {
        allegro_message("Erreur lors du chargement de l'image %s", image_path);
        // Gérer l'erreur comme nécessaire
    }
    genImage->x = x;
    genImage->y = y;
}

// Fonction pour rendre les contours de l'image transparents en utilisant une couleur spécifique
void make_transparent_color(BITMAP *bmp, int transparent_color) {
    int x, y;
    for (y = 0; y < bmp->h; y++) {
        for (x = 0; x < bmp->w; x++) {
            if (getpixel(bmp, x, y) == transparent_color) {
                putpixel(bmp, x, y, makecol(255, 0, 255)); // Rendre le pixel transparent
            }
        }
    }
}

// Fonction pour afficher l'image
void display_generated_image(BITMAP *bmp, GeneratedImage *genImage){
        if (genImage->image != NULL) {
            // Rendre les contours de l'image transparents en utilisant la couleur spécifique (rouge)
            make_transparent_color(genImage->image, makecol(255, 255, 255)); // Rouge = 255, Vert = 0, Bleu = 0
            draw_sprite(bmp, genImage->image, genImage->x, genImage->y); // Dessine avec la transparence simulée
        } else {
            allegro_message("L'image n'a pas été chargée correctement.");
            // Gérer l'erreur comme nécessaire
        }
    }


