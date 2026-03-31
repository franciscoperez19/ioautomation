#include "../io_internal.h"
#define PRESS 1
#define HOTKEY 2

// internal functions

void __keyboard_process__(KeyboardKey *keys, int keysLength) {
    int totalEvents = keysLength * 2;
    INPUT *inputs = calloc(totalEvents, sizeof(INPUT));
    
    for(int i = 0; i < keysLength; i++) {
        
        inputs[i].type = INPUT_KEYBOARD;
        inputs[i].ki.wVk = keys[i];
        inputs[i].ki.dwFlags = 0;
        // special keys need extended flag (UP,DOWN, DELETE, SUPR)
        if ((keys[i] >= 0x21 && keys[i] <= 0x2E) || (keys[i] >= 0xA0 && keys[i] <= 0xA5)) {
            inputs[i].ki.dwFlags |= KEYEVENTF_EXTENDEDKEY; 
        }
        
        int release = (totalEvents - 1) - i;    
        inputs[release].type = INPUT_KEYBOARD;
        inputs[release].ki.wVk = keys[i];
        inputs[release].ki.dwFlags = 2;
        if ((keys[i] >= 0x21 && keys[i] <= 0x2E) || (keys[i] >= 0xA0 && keys[i] <= 0xA5)) {
            inputs[release].ki.dwFlags |= KEYEVENTF_EXTENDEDKEY; 
        }
    }

    SendInput(totalEvents, inputs,sizeof(INPUT));
    free(inputs);
}

KeyboardKey* __key_process__(KeyboardKey *keys, int keysSize, int *newSize, int mode) {
    KeyboardKey *keysProcessed = calloc(keysSize*2, sizeof(KeyboardKey));
    int j = 0;
    for(int i = 0; i < keysSize; i++){
        // if upper
        if(keys[i] >= 0x41 && keys[i] <= 0x5A && mode == PRESS) {
            keysProcessed[j++] = KEY_SHIFTLEFT;
            keysProcessed[j++] = keys[i];
        } 
        // if lower
        else if (keys[i] >= 0x61 && keys[i] <= 0x7A) {
            KeyboardKey realKey = keys[i] - 0x20;
            keysProcessed[j++] = realKey;
        }
        else {
            keysProcessed[j++] = keys[i];
        }
    }

    *newSize = j;
    return keysProcessed;
}



/** 
*    @brief Simulate a key press 
*    @param ctx Pointer to context of library
*    @param key Key to press
*    @return Nothing
*
*/
void keyboard_press(const IOContext *ctx, KeyboardKey key) {
    KeyboardKey *keyRaw = calloc(1,sizeof(KeyboardKey));
    int newSize = 0;
    keyRaw[0] = key;
    KeyboardKey *keyProcessed = __key_process__(keyRaw, 1, &newSize, PRESS);
    __keyboard_process__(keyProcessed, newSize);
    free(keyProcessed);
    free(keyRaw);
}


/** 
*    @brief Simulate a simultaneous key combination 
*    @param ctx Pointer to context of library
*    @param keys Array of keys sequence
*    @param keysCount Amount of keys in array
*    @return Nothing
*
*/
void keyboard_hotkey(const IOContext *ctx, KeyboardKey *keys, int keysCount) {
    int newSize = 0;
    KeyboardKey *keyProcessed = __key_process__(keys,keysCount, &newSize, HOTKEY);

    __keyboard_process__(keyProcessed, newSize);
    free(keyProcessed);
}
