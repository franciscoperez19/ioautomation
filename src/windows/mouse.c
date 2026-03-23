#include "../io_internal.h"
#include <windows.h>



/** 
*    @brief Move mouse to the indicate pos 
*    @param ctx Pointer to context of library
*    @param x Mouse pos in the X axis
*    @param y Mouse pos in the Y axis
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_move (const IOContext *ctx, int x, int y) {

}


/** 
*    @brief Obtain mouse current position 
*    @param ctx Pointer to context of library
*    @param pos Array of 2 ints where posX and posY are saved  
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_posreader (const IOContext *ctx, int pos[2]) {

}


/** 
*    @brief Press any mouse button
*    @param ctx Pointer to context of library
*    @param action Mouse action to execute
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_action (const IOContext *ctx, MouseButton action) {
    SendInput()
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

}
