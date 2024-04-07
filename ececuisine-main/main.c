#include "MENU.h"

int main()
{
    current_user=1;
    init();
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);

    draw_menu(buffer);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    int menu_option = menu_select();

    switch (menu_option) {
        case OPTION_PLAY:
            while (!key[KEY_ESC]) {
                if (mouse_b & 1 && current_user == 3) {  // Vérifie si le bouton gauche de la souris est cliqué
                    rest(300); // Anti-rebond pour éviter les clics multiples
                    for (int i = 0; i < 3; i++) {
                        if (mouse_x > SCREEN_W / 4 * (i + 1) - 50 && mouse_x < SCREEN_W / 4 * (i + 1) + 50 &&
                            mouse_y > SCREEN_H / 2 - 25 && mouse_y < SCREEN_H / 2 + 25) {
                            level = i + 1;
                            current_user = 4; // Change l'état pour empêcher d'autres entrées
                            break;
                        }
                    }
                }

                if (keypressed()) {
                    int newkey = readkey();
                    char ASCII = newkey & 0xff; // Obtient le code ASCII de la touche
                    char scancode = newkey >> 8; // Obtient le scancode de la touche

                    if (level == 0 && current_user < 3) {
                        if ((ASCII >= 'A' && ASCII <= 'Z') || (ASCII >= 'a' && ASCII <= 'z') || (ASCII == ' ')) { // Permet les lettres et l'espace
                            if (current_user == 1 && user1_char_pos < 19) {
                                user1[user1_char_pos++] = ASCII;
                                user1[user1_char_pos] = '\0'; // Assure que la chaîne est toujours terminée correctement
                            } else if (current_user == 2 && user2_char_pos < 19) {
                                user2[user2_char_pos++] = ASCII;
                                user2[user2_char_pos] = '\0'; // Assure que la chaîne est toujours terminée correctement
                            }
                        }

                        if (scancode == KEY_BACKSPACE) { // Gère la suppression d'un caractère
                            if (current_user == 1 && user1_char_pos > 0) {
                                user1[--user1_char_pos] = '\0';
                            } else if (current_user == 2 && user2_char_pos > 0) {
                                user2[--user2_char_pos] = '\0';
                            }
                        }

                        if (scancode == KEY_ENTER) {
                            if (current_user == 1 && user1_char_pos > 0) {
                                current_user = 2;
                            } else if (current_user == 2 && user2_char_pos > 0) {
                                current_user = 3; // Prêt pour la sélection du niveau
                            }
                        }
                    }
                }

                draw_play_menu(buffer);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(20); // Donne du temps au CPU
            }
            break;
        case OPTION_LOAD:
// Code pour charger une partie
            break;
        case OPTION_RULES:
// Code pour afficher les règles
            break;
        default:
// Code si l'utilisateur quitte ou une option non valide est sélectionnée
            break;
    }

    deinit();
    return 0;
}END_OF_MAIN();