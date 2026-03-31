#include "io_internal.h"
#include <stdlib.h>
#ifdef _WIN32
    #define IO_FLUSH()
    #define IO_SLEEP(ms) Sleep(ms)
#else
    #define IO_FLUSH() XFlush(ctx->display)
    #define IO_SLEEP(ms) usleep(2000)
#endif

static void _smooth_mouse_movement(const IOContext *ctx, int initialPosition[2], int finalPosition[2]) {
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
