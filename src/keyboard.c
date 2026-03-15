#include "io_internal.h"
#include <unistd.h>


static void _key_sequence(const IOContext *ctx, KeyboardKey *keys, int keysLength){
    KeyCode codes[keysLength];

    for(int i = 0; i < keysLength; i++){
        codes[i] = XKeysymToKeycode(ctx->display, keys[i]);
        XTestFakeKeyEvent(ctx->display, codes[i], 1, 0);
    }
    XFlush(ctx->display);
    usleep(100);

    for(int i = keysLength - 1; i >= 0; i--){
        XTestFakeKeyEvent(ctx->display, codes[i], 0, 0);
    }

    XFlush(ctx->display);
    usleep(100);
}


void keyboard_press(const IOContext *ctx, KeyboardKey key) {
    if (key >= 0x41 && key <= 0x5a) {
        KeyboardKey keys[] = {KEY_SHIFTLEFT, key};
        _key_sequence(ctx, keys, 2);
    }
    else {
        _key_sequence(ctx,&key,1);
    }
}

void keyboard_hotkey(const IOContext *ctx, KeyboardKey *keys, int keysCount) {
    _key_sequence(ctx, keys, keysCount);
}

