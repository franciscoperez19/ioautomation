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

// keyboard functions

void keyboard_press(const IOContext *ctx, KeyboardKey key);

#endif 