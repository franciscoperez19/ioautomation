#include "../include/ioautomation.h"
#include <stdio.h>
#include <stdlib.h>

void test_mousemove(IOContext *ctx, int x, int y);
int* test_mouseread(IOContext *ctx);
void test_mouseaction(IOContext *ctx);

int main() {
    int x = 45, y = 12;
    IOContext *ctx = NULL;
    ctx = io_init();

    test_mousemove(ctx, x, y);
    int *pos = test_mouseread(ctx);

    if(pos[0] == x && pos[1] == y) {
        printf("[\033[32mOK\033[0m] Mouse movement test\n");
    }
    else {
        printf("[\033[31mFAIL\033[0m] Mouse movement test\n");
    }

    mouse_action(ctx,MOUSE_LEFT_CLICK);

    io_cleanup(ctx);
    free(pos);
    return 0;
}

void test_mousemove(IOContext *ctx, int x, int y) {
    if(mouse_move(ctx,x,y) == 0) {
        printf("Mouse move correctly %d, %d\n", x, y);
    }
}

int* test_mouseread(IOContext *ctx) {
    int *pos = malloc(2 * sizeof(int));
    if (mouse_posreader(ctx,pos) == 0) {
        printf("Mouse currently in position X = %d, Y = %d\n", pos[0], pos[1]);
    }
    else {
        printf("Impossible to read current mouse position");
    }
    return pos;
}

