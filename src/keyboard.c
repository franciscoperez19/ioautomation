#include "io_internal.h"
#include <unistd.h>
void keyboard_press(const IOContext *ctx, KeyboardKey key) {

    KeyCode keyAction = XKeysymToKeycode(ctx->display, key);
    KeyCode shift = XKeysymToKeycode(ctx->display, KEY_SHIFTLEFT);

    /* key is mayus */
    if (key >= 0x41 && key <= 0x5a) XTestFakeKeyEvent(ctx->display, shift, 1, 0);

    XTestFakeKeyEvent(ctx->display, keyAction, 1, 0);
    XTestFakeKeyEvent(ctx->display, keyAction, 0, 100);

    if (key >= 0x41 && key <= 0x5a) XTestFakeKeyEvent(ctx->display, shift, 0, 0);
    XFlush(ctx->display);
    usleep(100);
}