# IOAUTOMATION

![Platform: Linux | Windows](https://img.shields.io/badge/platform-Linux%20%7C%20Windows-blue)

A lightweight C library for Linux and Windows automation using X11 and WIN32 API. Designed for testing interfaces and high-performance automation.

## Features

Mouse: Move, Click (Left, Right, Middle), and Vertical Scroll.

Drag and drop: Precise smooth dragging for point A to B.

Mouse Position Reader: Real-time cursor coordinates.

Keyboard: Hotkey, press key and copy to clipboard functions

## Motivation

Pyautogui but less of ~20KB. The goal is provide a simple API for C developers without the overhead of Python

## Installation

**LINUX**

You need to install X11 and XTest development libraries:

```bash
sudo apt-get update
sudo apt-get install libx11-dev libxtst-dev
```

**WINDOWS**

You need to install mingw64 to compile and get *windows.h* header

If you install MSYS2 you can do:
```bash
pacman -S --needed mingw-w64-x86_64-toolchain
```
to install gcc and make

## Compilation

First, build the static library:
```bash
make lib
```
<mark>⚠ Note: You need ioautomation.h, ioconstants.h and libioautomation.a to link the library to your project.</mark>

**LINUX**

Then link with your project all the libraries:
```bash
gcc main.c -L. -lioautomation -lX11 -lXtst -o my_app
```
If you want to install the library in /usr/lib then:
```bash
sudo make install
```
and you can compile everywhere with:
```bash
gcc main.c -lioautomation -lX11 -lXtst -o my_app
```

**WINDOWS**

Then link your project with ioautomation library:
```bash
gcc main.c -L. -lioautomation -luser32 -lgdi32 -o my_app
```

## Example:

```C
#include "ioautomation.h"

int main() {
    IOContext *ctx = io_init();
    if (ctx == NULL) return 1;

    int start[2] = {100, 100};
    int end[2] = {500, 500};

    mouse_drag(ctx, start, end); 

    io_cleanup(ctx);
    return 0;
}
```
