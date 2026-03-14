#ifndef IO_INTERNAL_H
#define IO_INTERNAL_H
#include "../include/ioautomation.h"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

struct IOContext {
    Display *display;
    Window root;
};



#endif 