#include "../../include/ioautomation.h"
#include <windows.h>
#include <time.h>
/*
*   ==========================================================
*               IOAutomation Windows Keyboard Test
*   1. Open Edge via Windows Browser
*   2. Copy the URL of this repository on the Clipboard
*   3. Use Hotkeys to paste
*
*       If this helps your workflow, give this repo a STAR!
*   ===========================================================
*/

int main() {
    IOContext *ctx;
    KeyboardKey paste[] = {KEY_CTRLLEFT, KEY_V};
    ctx = io_init();

    Sleep(5000);
    keyboard_press(ctx, KEY_WINDOWS);
    Sleep(2000);
    keyboard_string(ctx, "opera");
    Sleep(1000);
    keyboard_press(ctx, KEY_ENTER);
    Sleep(1000);
    copy_clipboard(ctx, "https://github.com/franciscoperez19/ioautomation");
    Sleep(500);
    keyboard_hotkey(ctx, paste,2);
    Sleep(1000);
    keyboard_press(ctx, KEY_ENTER);    

    io_cleanup(ctx);

    return 0;
}