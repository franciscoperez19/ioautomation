#ifndef IOCONSTANTS_H
#define IOCONSTANTS_H

typedef enum{
    #ifdef _WIN32
        // mouse scroll in windows api is treaten differently
        MOUSE_LEFT_CLICK = 0x0002,
        MOUSE_MIDDLE_CLICK = 0x0020,
        MOUSE_RIGHT_CLICK = 0x0008,
        MOUSE_SCROLL_VERTICAL = 0,
        MOUSE_SCROLL_HORIZONTAL = 1,
    #else
        MOUSE_LEFT_CLICK = 1,
        MOUSE_MIDDLE_CLICK = 2,
        MOUSE_RIGHT_CLICK = 3,
        MOUSE_SCROLL_UP = 4,
        MOUSE_SCROLL_DOWN = 5
    #endif
} MouseButton;

typedef enum{
    #ifdef _WIN32
        KEY_ENTER = 0x0D,
        KEY_ESC = 0x1B,
        KEY_SPACE = 0x20,
        KEY_BACKSPACE = 0x08,
        KEY_CLEAR = 0x0C,
        KEY_CAPITAL = 0x14,
        KEY_NEXT = 0x22,
        KEY_PRIOR = 0x21,
        KEY_TAB = 0x09,
        KEY_CTRLLEFT = 0xA2,
        KEY_WINDOWS = 0x5B,
        KEY_END = 0x23,
        KEY_HOME = 0x24,
        KEY_SHIFTLEFT = 0xA0,
        KEY_ALTLEFT = 0xA4,
        KEY_UP = 0x26,
        KEY_DOWN = 0x28,
        KEY_LEFT = 0x25,
        KEY_RIGHT = 0x27,
    #else
        KEY_ENTER = 0xff0d,
        KEY_ESC = 0xff1b,
        KEY_TAB = 0xff09,
        KEY_SPACE = 0x0020,
        KEY_BACKSPACE = 0xff08,
        KEY_UP = 0xff52,
        KEY_DOWN = 0xff54,
        KEY_LEFT = 0xff51,
        KEY_RIGHT = 0xff53,
        KEY_SHIFTLEFT = 0xffe1,
        KEY_CTRLLEFT = 0xffe3,
        KEY_ALTLEFT = 0xffe9,
    #endif
    KEY_A = 0x41,
    KEY_B = 0x42,
    KEY_C = 0x43,
    KEY_D = 0x44,
    KEY_E = 0x45,
    KEY_F = 0x46,
    KEY_G = 0x47,
    KEY_H = 0x48,
    KEY_I = 0x49,
    KEY_J = 0x4A,
    KEY_K = 0x4B,
    KEY_L = 0x4C,
    KEY_M = 0x4D,
    KEY_N = 0x4E,
    KEY_O = 0x4F,
    KEY_P = 0x50,
    KEY_Q = 0x51,
    KEY_R = 0x52,
    KEY_S = 0x53,
    KEY_T = 0x54,
    KEY_U = 0x55,
    KEY_V = 0x56,
    KEY_W = 0x57,
    KEY_X = 0x58,
    KEY_Y = 0x59,
    KEY_Z = 0x5A,
    #ifdef __linux__ 
        KEY_a = 0x61,
        KEY_b = 0x62,
        KEY_c = 0x63,
        KEY_d = 0x64,
        KEY_e = 0x65,
        KEY_f = 0x66,
        KEY_g = 0x67,
        KEY_h = 0x68,
        KEY_i = 0x69,
        KEY_j = 0x6A,
        KEY_k = 0x6B,
        KEY_l = 0x6C,
        KEY_m = 0x6D,
        KEY_n = 0x6E,
        KEY_o = 0x6F,
        KEY_p = 0x70,
        KEY_q = 0x71,
        KEY_r = 0x72,
        KEY_s = 0x73,
        KEY_t = 0x74,
        KEY_u = 0x75,
        KEY_v = 0x76,
        KEY_w = 0x77,
        KEY_x = 0x78,
        KEY_y = 0x79,
        KEY_z = 0x7A
    #endif
} KeyboardKey;


#endif  