#include "../../include/ioautomation.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
*   ==========================================================
*               IOAutomation Linux Mouse Test
*   1. Move mouse to x,y
*   2. Read position of mouse
*   3. Compare position with x,y
*   4. Check mouse drag function
*
*   (Code on comment check mouse click and mouse scroll)
*
*       If this helps your workflow, give this repo a STAR!
*   ===========================================================
*/



void test_mousemove(IOContext *ctx, int x, int y);
int* test_mouseread(IOContext *ctx);

int main() {
    int x = 45, y = 12;
    IOContext *ctx = NULL;
    ctx = io_init();

    test_mousemove(ctx, x, y);
    usleep(200);
    
    int *pos = test_mouseread(ctx);
    if (!pos) return -1;

    if(pos[0] == x && pos[1] == y) {
        printf("[\033[32mOK\033[0m] Mouse movement test\n");
    }
    else {
        printf("[\033[31mFAIL\033[0m] Mouse movement test\n");
    }
    /*
    mouse_action(ctx,MOUSE_LEFT_CLICK);
    sleep(2);
    mouse_scroll(ctx,MOUSE_SCROLL_DOWN, 1);
    sleep(1);
    mouse_scroll(ctx,MOUSE_SCROLL_DOWN, 1);
    sleep(1);
    mouse_scroll(ctx,MOUSE_SCROLL_DOWN, 1);
    sleep(1);
    mouse_scroll(ctx,MOUSE_SCROLL_DOWN, 1);
    sleep(1);
    mouse_scroll(ctx,MOUSE_SCROLL_DOWN, 1);
    */
    sleep(2);
    int initialPos[2] = {2000,2000};
    int finalPos[2] = {45,12};
    mouse_drag(ctx,initialPos,finalPos);

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

