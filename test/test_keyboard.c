#include "ioautomation.h"
#include <unistd.h>

int main() {
    IOContext *ctx;
    ctx = io_init();

    sleep(2);
    keyboard_press(ctx,KEY_H);
    keyboard_press(ctx,KEY_e);
    keyboard_press(ctx,KEY_l);
    keyboard_press(ctx,KEY_l);
    keyboard_press(ctx,KEY_o);
   
    io_cleanup(ctx);

    return 0;
}