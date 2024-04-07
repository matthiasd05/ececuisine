#include "BUFFER.h"
void init() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_W, SCREEN_H, 0, 0);
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    show_mouse(screen);
}
void deinit() {
    clear_keybuf();
    destroy_bitmap(buffer);
}