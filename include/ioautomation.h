#ifndef IOAUTOMATION_H
#define IOAUTOMATION_H
#include "ioconstants.h"

typedef struct IOContext IOContext;


// init library context
IOContext* io_init();
void io_cleanup(IOContext *ctx);


// mouse functions

int mouse_move (const IOContext *ctx, int x, int y);
int mouse_posreader (const IOContext *ctx, int pos[2]);
int mouse_action (const IOContext *ctx, MouseButton action);
int mouse_scroll(const IOContext *ctx, MouseButton scroll, int amount);
int mouse_drag(const IOContext *ctx, int initialPosition[2], int finalPosition[2]);

// keyboard functions

void keyboard_press(const IOContext *ctx, KeyboardKey key);
void keyboard_hotkey(const IOContext *ctx, KeyboardKey *keys, int keysCount);

#endif 