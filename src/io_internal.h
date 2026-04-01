#ifndef IO_INTERNAL_H
#define IO_INTERNAL_H
#include "../include/ioautomation.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <X11/Xlib.h>
    #include <X11/extensions/XTest.h>
#endif

struct IOContext {
    #ifdef _WIN32
        int lasterror;
    #else
        Display *display;
        Window root;
    #endif
};

// common functions

void __smooth_mouse_movement__(const IOContext *ctx, int initialPosition[2], int finalPosition[2]);

#endif 