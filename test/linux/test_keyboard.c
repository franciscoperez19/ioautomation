#include "../../include/ioautomation.h"
#include <unistd.h>

int main() {
    IOContext *ctx;
    ctx = io_init();
    KeyboardKey keys[] = {KEY_CTRLLEFT, KEY_ALTLEFT, KEY_T};

    sleep(2);
    keyboard_hotkey(ctx,keys,3);
    sleep(2);
    keyboard_press(ctx,KEY_n);
    keyboard_press(ctx,KEY_a);
    keyboard_press(ctx,KEY_n);
    keyboard_press(ctx,KEY_o);
    keyboard_press(ctx,KEY_ENTER);
    sleep(2);
    KeyboardKey text[] = {KEY_H, KEY_e, KEY_l,KEY_l,KEY_o, KEY_SPACE, KEY_w, KEY_o, KEY_r, KEY_l, KEY_d};

    for(int i = 0; i < (int) (sizeof(text)/sizeof(text[0])); i++){
        keyboard_press(ctx, text[i]);
    }

    io_cleanup(ctx);

    return 0;
}