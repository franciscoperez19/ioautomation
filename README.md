# IOAUTOMATION

A lightweight C library for Linux automation using X11. Designed for testing interfaces and high-performance automation.

## Features

Mouse: Move, Click (Left, Right, Middle), and Vertical Scroll.

Drag and drop: Precise smooth dragging for point A to B.

Mouse Position Reader: Real-time cursor coordinates using XQueryPointer but oversimplified to the user.

Keyboard: Hotkey and press key functions

## Motivation

Pyautogui but less of ~20KB. The goal is provide a simple API for C developers without the overhead of Python

## Installation

You need to install X11 and XTest development libraries:

```bash
sudo apt-get update
sudo apt-get install libx11-dev libxtst-dev
```

## Compilation

First, build the static library:
```bash
make lib
```
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

## Example:

```C
#include "ioautomation.h"

int main() {
    IOContext ctx;
    if (io_init(&ctx) != 0) return 1;

    int start[2] = {100, 100};
    int end[2] = {500, 500};

    mouse_drag(&ctx, start, end); 

    io_free(&ctx);
    return 0;
}
```
