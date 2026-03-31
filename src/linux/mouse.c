#include "../io_internal.h"
#include <unistd.h>


/** 
*    @brief Obtain mouse current position 
*    @param ctx Pointer to context of library
*    @param pos Array of 2 ints where posX and posY are saved  
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_posreader(const IOContext *ctx, int pos[2]) {
    Window w_returned;
    int pointer_x, pointer_y;
    int win_x, win_y;
    unsigned int mask;
    

    if (XQueryPointer(ctx->display, ctx->root, &w_returned, &w_returned, &pointer_x, 
                        &pointer_y, &win_x, &win_y, &mask)) {
        
        pos[0] = pointer_x;
        pos[1] = pointer_y;
        return 0;
    }
    else {
        return -1;
    }
}

/** 
*    @brief Move mouse to the indicate pos 
*    @param ctx Pointer to context of library
*    @param x Mouse pos in the X axis
*    @param y Mouse pos in the Y axis
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_move(const IOContext *ctx, int x, int y) {
    if (ctx == NULL) return -1;
    XTestFakeMotionEvent(ctx->display, -1, x,y,0);
    XFlush(ctx->display);

    return 0;
}


/** 
*    @brief Press any mouse button
*    @param ctx Pointer to context of library
*    @param action Mouse action to execute
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_action (const IOContext *ctx, MouseButton action) {
    if(ctx == NULL || !XTestFakeButtonEvent(ctx->display,action,True,0) ) return -1;
    XFlush(ctx->display);
    if(!XTestFakeButtonEvent(ctx->display,action,False,10)) return -1;
    XFlush(ctx->display);
    return 0;
}

/** 
*    @brief Scroll down/up
*    @param ctx Pointer to context of library
*    @param scroll Mouse button constant (eg. MOUSE_SCROLL_UP)
*    @param amount How much want to scroll
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_scroll(const IOContext *ctx, MouseButton scroll, int amount) {
    if(ctx == NULL || (scroll != MOUSE_SCROLL_DOWN && scroll != MOUSE_SCROLL_UP)) return -1;
    
    for(int i = 0; i < amount; i++) {
        XTestFakeButtonEvent(ctx->display,scroll,True,0);
        usleep(50);
        if(!XTestFakeButtonEvent(ctx->display,scroll,False,0)) return -1;
    }
    XFlush(ctx->display);
    return 0;
}


/** 
*    @brief Move the mouse while holding left click
*    @param ctx Pointer to context of library
*    @param initalPosition Position where pointer hold left click [0] = X, [1] = Y
*    @param finalPosiition Position where pointer drop left click [0] = X, [1] = Y
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_drag(const IOContext *ctx, int initialPosition[2], int finalPosition[2]) {
    if ( ctx == NULL || (initialPosition == NULL || finalPosition == NULL)) return -1;

    mouse_move(ctx,initialPosition[0],initialPosition[1]);
    XTestFakeButtonEvent(ctx->display, MOUSE_LEFT_CLICK, True, 0);
    
    __smooth_mouse_movement__(ctx,initialPosition,finalPosition);

    mouse_move(ctx,finalPosition[0],finalPosition[1]);
    XTestFakeButtonEvent(ctx->display, MOUSE_LEFT_CLICK, False, 0);
    XFlush(ctx->display);

    return 0;
}