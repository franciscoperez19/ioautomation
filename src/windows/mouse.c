#include "../io_internal.h"
#define CUSTOM_WHEEL_DELTA 30

// internal function to process the 2 actions of the mouse first DOWN then UP

int __mousebutton_process__(MouseButton action) {
    INPUT inputs[2] = {0};

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = action;

    inputs[1].type = INPUT_MOUSE;

    if (action == MOUSE_LEFT_CLICK) {
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    }
    else if (action == MOUSE_RIGHT_CLICK) {
        inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    }
    else {
        inputs[1].mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
    }


    // sendInput return total of events executed
    if (SendInput(2,inputs, sizeof(INPUT)) == 2) return 0;
    else return -1;
}



/** 
*    @brief Move mouse to the indicate pos 
*    @param ctx Pointer to context of library
*    @param x Mouse pos in the X axis
*    @param y Mouse pos in the Y axis
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_move (const IOContext *ctx, int x, int y) {
    if (SetCursorPos(x,y) == 0) return -1;
    else return 0;
}


/** 
*    @brief Obtain mouse current position 
*    @param ctx Pointer to context of library
*    @param pos Array of 2 ints where posX and posY are saved  
*    @return -1 in case of error, otherwise, 0
*
*/
int mouse_posreader (const IOContext *ctx, int pos[2]) {
    POINT p;
    
    // GetCursorPos fill the struct POINT and return 1 if was possible or 0 in case of error
    if (GetCursorPos(&p) == 0) return -1;


    pos[0] = p.x;
    pos[1] = p.y;
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
    return __mousebutton_process__(action);
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
    INPUT inputs[1] = {0};
    inputs[0].type = INPUT_MOUSE;
    if (scroll == MOUSE_SCROLL_HORIZONTAL) inputs[0].mi.dwFlags = MOUSEEVENTF_HWHEEL;
    else if (scroll == MOUSE_SCROLL_VERTICAL) inputs[0].mi.dwFlags = MOUSEEVENTF_WHEEL;
    else return -1;
    
    // CUSTOM_WHEEL_DELTA is the (standard value / 4) for one notch of the mouse wheel.
    // positive: scroll up/right, negative: scroll down/left.
    inputs[0].mi.mouseData = (DWORD) (amount * CUSTOM_WHEEL_DELTA);

    if(SendInput(1,inputs,sizeof(INPUT)) == 1) return 0;
    else return -1;
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
