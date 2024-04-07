#include "MENU.h"


void draw_rounded_rectangle(BITMAP *bmp, int x, int y, int width, int height, int radius, int color) {
    // Dessine les coins arrondis
    circlefill(bmp, x + radius, y + radius, radius, color); // Coin supérieur gauche
    circlefill(bmp, x + width - radius, y + radius, radius, color); // Coin supérieur droit
    circlefill(bmp, x + radius, y + height - radius, radius, color); // Coin inférieur gauche
    circlefill(bmp, x + width - radius, y + height - radius, radius, color); // Coin inférieur droit

    // Dessine les rectangles pour remplir l'intérieur et les côtés
    rectfill(bmp, x + radius, y, x + width - radius, y + height, color); // Centre
    rectfill(bmp, x, y + radius, x + width, y + height - radius, color); // Côtés
}

void draw_menu(BITMAP *bmp) {
    // Charge l'image de fond
    BITMAP *background = load_bitmap("ECE/MENU.bmp", NULL);
    if (!background) {
        allegro_message("Impossible de charger l'image de fond MENU.bmp");
        return; // Ne continue pas si l'image ne peut pas être chargée
    }

    // Dessine l'image de fond sur le bitmap de destination
    blit(background, bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    // Définit les positions et tailles des boutons
    int btn_width = 200;
    int btn_height = 50;
    int radius = 10; // Rayon pour les coins arrondis
    int start_x = SCREEN_W / 2 - btn_width / 2;
    int start_y = SCREEN_H / 2 - 75;
    int padding = 10; // Espace entre les boutons

    // Dessine les boutons du menu avec des bordures arrondies
    for (int i = 0; i < 3; i++) {
        int btn_y = start_y + i * (btn_height + padding);
        int btn_color = makecol(100, 100, 200); // Couleur du bouton
        draw_rounded_rectangle(bmp, start_x, btn_y, btn_width, btn_height, radius, btn_color);

        char *btn_text = "";
        switch (i) {
            case 0: btn_text = "Jouer"; break;
            case 1: btn_text = "Charger une partie"; break;
            case 2: btn_text = "Règles"; break;
        }

        // Centre le texte sur le bouton
        textout_centre_ex(bmp, font, btn_text, start_x + btn_width / 2, btn_y + btn_height / 2 - text_height(font) / 2, makecol(255, 255, 255), -1);
    }

    // Libère la mémoire allouée pour l'image de fond
    destroy_bitmap(background);
}

int menu_select() {
    show_mouse(screen);
    int btn_width = 200;
    int btn_height = 50;
    int start_x = SCREEN_W / 2 - btn_width / 2;
    int start_y = SCREEN_H / 2 - 75;
    int padding = 10;

    while (!key[KEY_ESC]) {
        if (mouse_b & 1) { // Si le bouton gauche de la souris est cliqué
            for (int i = 0; i < 3; i++) {
                int btn_y = start_y + i * (btn_height + padding);
                if (mouse_x >= start_x && mouse_x <= start_x + btn_width && mouse_y >= btn_y && mouse_y <= btn_y + btn_height) {
                    return i + 1; // Retourne 1 pour jouer, 2 pour charger, 3 pour règles
                }
            }
        }
        rest(100); // Évite la surcharge du CPU
    }

    return 0; // Retourne 0 si l'utilisateur appuie sur ESC
}

void draw_level_button(BITMAP *bmp, int x, int y, int width, int height, AL_CONST char *text, int color) {
    int border_radius = 10; // Pour des bordures arrondies
    // Dessine l'ombre du bouton
    rectfill(bmp, x + 2, y + 2, x + width + 2, y + height + 2, makecol(0, 0, 0));
    // Dessine le bouton avec bordure arrondie (simulé ici par une couleur de fond légèrement différente)
    rectfill(bmp, x, y, x + width, y + height, color);
    // Dessine le texte du bouton
    textout_centre_ex(bmp, font, text, x + width / 2, y + height / 2 - text_height(font) / 2, makecol(255, 255, 255), -1);
}

void draw_level_selection(BITMAP *bmp) {
    // Choix de couleurs plus vives
    int colors[3] = {
            makecol(231, 76, 60),  // Rouge
            makecol(46, 204, 113), // Vert
            makecol(52, 152, 219)  // Bleu
    };

    for (int i = 0; i < 3; i++) {
        int x = SCREEN_W / 4 * (i + 1) - 50;
        int y = SCREEN_H / 2 - 25;
        char lvl[3]; // Suffisant pour "n" + '\0'
        sprintf(lvl, "%d", i + 1);
        draw_level_button(bmp, x, y, 100, 50, lvl, colors[i]);
    }
}


// Fonction pour dessiner une boîte de texte avec ombre pour plus de profondeur
void draw_text_box(BITMAP *bmp, int x, int y, const char *text, int highlight) {
    // Calcule la largeur et la hauteur de la boîte basées sur le texte
    int box_width = text_length(font, text) + 20;
    int box_height = text_height(font) + 10;

    // Définit la couleur de la boîte en fonction de si elle est mise en évidence ou non
    int color = highlight ? makecol(212, 115, 212): makecol(149, 165, 149);
    int shadow_color = makecol(50, 50, 50); // Couleur de l'ombre pour un effet de profondeur

    // Dessine l'ombre de la boîte
    rectfill(bmp, x - 10 + 2, y - 5 + 2, x + box_width + 2, y + box_height + 2, shadow_color);

    // Dessine la boîte de texte principale
    rectfill(bmp, x - 10, y - 5, x + box_width, y + box_height, color);
    rect(bmp, x - 10, y - 5, x + box_width, y + box_height, makecol(0, 0, 0));

    // Dessine le texte dans la boîte
    textout_ex(bmp, font, text, x, y, makecol(0, 0, 0), -1);
}

// Fonction pour dessiner le menu de jeu, améliorée pour une meilleure présentation
void draw_play_menu(BITMAP *bmp) {
    BITMAP *background = load_bitmap("ECE/JOUEUR.bmp", NULL);
    if (!background) {
        allegro_message("Impossible de charger l'image de fond MENU.bmp");
        return; // Ne continue pas si l'image ne peut pas être chargée
    }
    // Dessine l'image de fond directement sur bmp, couvrant toute la surface
    blit(background, bmp, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    int center_x = SCREEN_W / 2;
    int quarter_screen_h = SCREEN_H / 4;

    // Ici, vous pouvez continuer à dessiner le reste de vos éléments d'UI par-dessus l'image de fond
    if (level == 0) {
        if (current_user <= 2) {
            draw_text_box(bmp, center_x - 150, quarter_screen_h - 30, "Entrez le nom du Joueur 1:", current_user == 1);
            draw_text_box(bmp, center_x - 150, 2 * quarter_screen_h - 30, "Entrez le nom du Joueur 2:", current_user == 2);
            draw_text_box(bmp, center_x - 100, quarter_screen_h + 20, user1, 0);
            draw_text_box(bmp, center_x - 100, 2 * quarter_screen_h + 20, user2, 0);
        } else {
            // Fonction hypothétique pour dessiner la sélection du niveau
            draw_level_selection(bmp);
        }
    }
    if (level == 1) {
        draw_level_1(bmp);
    }
    else if (level == 2) {
        draw_level_2(bmp);
    }
    else if (level == 3) {
        draw_level_3(bmp);
    }
    destroy_bitmap(background);
}
// Correction: Cette fonction doit juste détecter quelle sélection a été faite et renvoyer ce choix.
int select_level() {
    int selected_level = 0;

    // Supposons que la zone de chaque bouton de niveau a été dessinée par draw_level_selection
    // et que nous vérifions simplement si la souris est cliquée dans ces zones.
    if (mouse_b & 1) {
        if (mouse_x >= (SCREEN_W / 4 * 1 - 50) && mouse_x <= (SCREEN_W / 4 * 1 + 50) &&
            mouse_y >= (SCREEN_H / 2 - 25) && mouse_y <= (SCREEN_H / 2 + 25)) {
            selected_level = 1; // Niveau 1 sélectionné
        } else if (mouse_x >= (SCREEN_W / 4 * 2 - 50) && mouse_x <= (SCREEN_W / 4 * 2 + 50) &&
                   mouse_y >= (SCREEN_H / 2 - 25) && mouse_y <= (SCREEN_H / 2 + 25)) {
            selected_level = 2; // Niveau 2 sélectionné
        } else if (mouse_x >= (SCREEN_W / 4 * 3 - 50) && mouse_x <= (SCREEN_W / 4 * 3 + 50) &&
                   mouse_y >= (SCREEN_H / 2 - 25) && mouse_y <= (SCREEN_H / 2 + 25)) {
            selected_level = 3; // Niveau 3 sélectionné
        }
    }

    return selected_level; // Retourne le niveau sélectionné, 0 si aucune sélection
}






