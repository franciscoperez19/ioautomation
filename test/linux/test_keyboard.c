#include "../../include/ioautomation.h"
#include <unistd.h>


/*
*   ==========================================================
*               IOAutomation Linux Keyboard Test
*   1. Open a new terminal with hotkey Ctrl+Alt+T
*   2. Press the sequence "nano" + ENTER
*   3. Write Hello World with the function string
*
*       If this helps your workflow, give this repo a STAR!
*   ===========================================================
*/



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
    keyboard_string(ctx, "Hello World");

    io_cleanup(ctx);

    return 0;
}