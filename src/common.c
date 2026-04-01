#include "io_internal.h"
#include <stdlib.h>
#ifdef _WIN32
    #define IO_FLUSH()
    #define IO_SLEEP(ms) Sleep(ms)
#else
    #define IO_FLUSH() XFlush(ctx->display)
    #define IO_SLEEP(ms) usleep(2000)
#endif

void __smooth_mouse_movement__(const IOContext *ctx, int initialPosition[2], int finalPosition[2]) {
     int difX,difY, difTotal, n;
    // absolute value of cords to make a smooth mouse move
    if(initialPosition[0] > finalPosition[0]) {
        difX = initialPosition[0] - finalPosition[0];
    }
    else difX = finalPosition[0] - initialPosition[0];

    if(initialPosition[1] > finalPosition[1]) {
        difY = initialPosition[1] - finalPosition[1];
    }
    else difY = finalPosition[1] - initialPosition[1];

    difTotal = difX + difY;
    if ((n = (int) difTotal / 5) < 5) n = 5;

    float posX = initialPosition[0], posY = initialPosition[1];
    float incX = (float) (finalPosition[0] - initialPosition[0]) / n;
    float incY = (float) (finalPosition[1] - initialPosition[1]) / n;
    for(int i = 0; i < n; i++) {
        posX += incX;
        posY += incY;
        mouse_move(ctx,(int) posX,(int) posY);
      
    }
}

void keyboard_string (const IOContext *ctx, const char *string) {
    int i = 0;
    while(string[i] != '\0') {
        // if letter
        if ((string[i] >= 0x41 && string[i] <= 0x5A) || (string[i] >= 0x61 && string[i] <= 0x7A)) {
            keyboard_press(ctx, string[i]);
        }
        // if space or number
        else if (string[i] == 0x20 || (string[i] >= 0x30 && string[i] <= 0x39)) keyboard_press(ctx, string[i]);
        // special characters case not implemented 

        i++;
    }
}