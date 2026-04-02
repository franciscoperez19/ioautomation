#include "../../include/ioautomation.h"
#include <windows.h>
#include <stdio.h>

/*
*   ==========================================================
*               IOAutomation Windows Keyboard Test
*   1. Read actual position in pos1
*   2. Print this position on screen
*   3. Mouse drag starting in pos1 to pos2
*
*   (Code on comment check mouse click and mouse move)
*
*       If this helps your workflow, give this repo a STAR!
*   ===========================================================
*/


int main() {
    IOContext *ctx;
    ctx = io_init();
    int i = 0;
    int pos1[] = {725,438};
    int pos2[] = {1000,438};

    Sleep(5000);

    while(i < 5){
        
        mouse_posreader(ctx, pos1);
        printf("Actual position of mouse: x - %d, y - %d\n", pos1[0], pos1[1]);
        //mouse_action(NULL, MOUSE_LEFT_CLICK);
        
        mouse_drag(ctx,pos1,pos2);
        Sleep(5000);
        //mouse_move(NULL,pos[0],pos[1]);
        i++;
    }

    io_cleanup(ctx);

}