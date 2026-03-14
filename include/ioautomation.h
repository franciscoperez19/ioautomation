#ifndef IOAUTOMATION_H
#define IOAUTOMATION_H

typedef struct IOContext IOContext;

typedef enum{
    MOUSE_LEFT_CLICK = 1,
    MOUSE_MIDDLE_CLICK = 2,
    MOUSE_RIGHT_CLICK = 3,
    MOUSE_SCROLL_UP = 4,
    MOUSE_SCROLL_DOWN = 5,
} MouseButton;


// init library context
IOContext* io_init();
void io_cleanup(IOContext *ctx);


// mouse functions

int mouse_move (const IOContext *ctx, int x, int y);
int mouse_posreader (const IOContext *ctx, int pos[2]);
int mouse_action (const IOContext *ctx, MouseButton action);

#endif 