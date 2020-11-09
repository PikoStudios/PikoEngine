
#include <SDL2/SDL.h>
#include "Event.h"

// PikoEngine Input Handler

// Licensing Details: KeyPressed is a alterted version of SDL2s SDL_KeyCode enum


typedef enum
{
    UNKNOWN = 0,

    RETURN = '\r',
    ESCAPE = '\033',
    BACKSPACE = '\b',
    TAB = '\t',
    SPACE = ' ',
    EXCLAIM = '!',
    QUOTEDBL = '"',
    HASH = '#',
    PERCENT = '%',
    DOLLAR = '$',
    AMPERSAND = '&',
    QUOTE = '\'',
    LEFTPAREN = '(',
    RIGHTPAREN = ')',
    ASTERISK = '*',
    PLUS = '+',
    COMMA = ',',
    MINUS = '-',
    PERIOD = '.',
    SLASH = '/',
    _0 = '0',
    _1 = '1',
    _2 = '2',
    _3 = '3',
    _4 = '4',
    _5 = '5',
    _6 = '6',
    _7 = '7',
    _8 = '8',
    _9 = '9',
    COLON = ':',
    SEMICOLON = ';',
    LESS = '<',
    EQUALS = '=',
    GREATER = '>',
    QUESTION = '?',
    AT = '@',

    LEFTBRACKET = '[',
    BACKSLASH = '\\',
    RIGHTBRACKET = ']',
    CARET = '^',
    UNDERSCORE = '_',
    BACKQUOTE = '`',
    a = 'a',
    b = 'b',
    c = 'c',
    d = 'd',
    e = 'e',
    f = 'f',
    g = 'g',
    h = 'h',
    i = 'i',
    j = 'j',
    k = 'k',
    l = 'l',
    m = 'm',
    n = 'n',
    o = 'o',
    p = 'p',
    q = 'q',
    r = 'r',
    s = 's',
    t = 't',
    u = 'u',
    v = 'v',
    w = 'w',
    x = 'x',
    y = 'y',
    z = 'z',

    CAPSLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK),

    F1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1),
    F2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2),
    F3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3),
    F4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4),
    F5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5),
    F6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6),
    F7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7),
    F8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8),
    F9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9),
    F10 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10),
    F11 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11),
    F12 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12),

    PRINTSCREEN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN),
    SCROLLLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK),
    PAUSE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE),
    INSERT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT),
    HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME),
    PAGEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP),
    DELETE = '\177',
    END = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END),
    PAGEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN),
    RIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT),
    LEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT),
    DOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN),
    UP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP),

    NUMLOCKCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR),
    KP_DIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE),
    KP_MULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY),
    KP_MINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS),
    KP_PLUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS),
    KP_ENTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER),
    KP_1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1),
    KP_2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2),
    KP_3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3),
    KP_4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4),
    KP_5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5),
    KP_6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6),
    KP_7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7),
    KP_8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8),
    KP_9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9),
    KP_0 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0),
    KP_PERIOD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD),

    APPLICATION = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION),
    POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER),
    KP_EQUALS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS),
    F13 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13),
    F14 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14),
    F15 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15),
    F16 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16),
    F17 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17),
    F18 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18),
    F19 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19),
    F20 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20),
    F21 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21),
    F22 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22),
    F23 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23),
    F24 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24),
    EXECUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE),
    HELP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP),
    MENU = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU),
    SELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT),
    STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP),
    AGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN),
    UNDO = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO),
    CUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT),
    COPY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY),
    PASTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE),
    FIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND),
    MUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE),
    VOLUMEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP),
    VOLUMEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN),
    KP_COMMA = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA),
    KP_EQUALSAS400 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400),

    ALTERASE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE),
    SYSREQ = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ),
    CANCEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL),
    CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR),
    PRIOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR),
    RETURN2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2),
    SEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR),
    OUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT),
    OPER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER),
    CLEARAGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN),
    CRSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL),
    EXSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL),

    KP_00 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00),
    KP_000 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000),
    THOUSANDSSEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR),
    DECIMALSEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR),
    CURRENCYUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT),
    CURRENCYSUBUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT),
    KP_LEFTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN),
    KP_RIGHTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN),
    KP_LEFTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE),
    KP_RIGHTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE),
    KP_TAB = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB),
    KP_BACKSPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE),
    KP_A = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A),
    KP_B = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B),
    KP_C = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C),
    KP_D = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D),
    KP_E = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E),
    KP_F = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F),
    KP_XOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR),
    KP_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER),
    KP_PERCENT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT),
    KP_LESS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS),
    KP_GREATER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER),
    KP_AMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND),
    KP_DBLAMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND),
    KP_VERTICALBAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR),
    KP_DBLVERTICALBAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR),
    KP_COLON = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON),
    KP_HASH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH),
    KP_SPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE),
    KP_AT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT),
    KP_EXCLAM = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM),
    KP_MEMSTORE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE),
    KP_MEMRECALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL),
    KP_MEMCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR),
    KP_MEMADD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD),
    KP_MEMSUBTRACT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT),
    KP_MEMMULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY),
    KP_MEMDIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE),
    KP_PLUSMINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS),
    KP_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR),
    KP_CLEARENTRY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY),
    KP_BINARY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY),
    KP_OCTAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL),
    KP_DECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL),
    KP_HEXADECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL),

    LCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL),
    LSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT),
    LALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT),
    LGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI),
    RCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL),
    RSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT),
    RALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT),
    RGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI),

    MODE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE),

    AUDIONEXT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT),
    AUDIOPREV = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV),
    AUDIOSTOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP),
    AUDIOPLAY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY),
    AUDIOMUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE),
    MEDIASELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT),
    WWW = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW),
    MAIL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL),
    CALCULATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR),
    COMPUTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER),
    AC_SEARCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH),
    AC_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME),
    AC_BACK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK),
    AC_FORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD),
    AC_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP),
    AC_REFRESH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH),
    AC_BOOKMARKS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS),

    BRIGHTNESSDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN),
    BRIGHTNESSUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP),
    DISPLAYSWITCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH),
    KBDILLUMTOGGLE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE),
    KBDILLUMDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN),
    KBDILLUMUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP),
    EJECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT),
    SLEEP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP),
    APP1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP1),
    APP2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP2),

    AUDIOREWIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOREWIND),
    AUDIOFASTFORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOFASTFORWARD)
} KeyPressed;


KeyPressed GetKeyPressed(EngineEvent event)
{
    switch (event.___event.type) // TODO: find a better way to do this
    {
    case SDL_KEYDOWN:
        switch (event.___event.key.keysym.sym)
        {
        case SDLK_LEFT:
            return LEFT;
            break;
        
        case SDLK_RIGHT:
            return RIGHT;
            break;
        case SDLK_UP:
            return UP;
            break;
        
        case SDLK_DOWN:
            return DOWN;
            break;
        
        case SDLK_0:
            return _0;
            break;

        case SDLK_1:
            return _1;
            break;
        
        case SDLK_2:
            return _2;
            break;
        
        case SDLK_3:
            return _3;
            break;

        case SDLK_4: return _4; break;

        case SDLK_5: return _5; break;

        case SDLK_6: return _6; break;
        case SDLK_7: return _7; break;
        case SDLK_8: return _8; break;
        case SDLK_9: return _9; break;
        case SDLK_UNKNOWN: return UNKNOWN; break;
        case SDLK_RETURN: return RETURN; break;
        case SDLK_ESCAPE: return ESCAPE; break;
        case SDLK_BACKSPACE: return BACKSPACE; break;
        case SDLK_TAB: return TAB; break;
        case SDLK_SPACE: return SPACE; break;
        case SDLK_EXCLAIM: return EXCLAIM; break;
        case SDLK_QUOTEDBL: return QUOTEDBL; break;
        case SDLK_HASH: return HASH; break;
        case SDLK_PERCENT: return PERCENT; break;
        case SDLK_DOLLAR: return DOLLAR; break;
        case SDLK_AMPERSAND: return AMPERSAND; break;
        case SDLK_QUOTE: return QUOTE; break;
        case SDLK_LEFTPAREN: return LEFTPAREN; break;
        case SDLK_RIGHTPAREN: return RIGHTPAREN; break;
        case SDLK_ASTERISK: return ASTERISK; break;
        // case SDLK_: return ; break;
        case SDLK_PLUS: return PLUS; break;
        case SDLK_COMMA: return COMMA; break;
        case SDLK_MINUS: return MINUS; break;
        case SDLK_PERIOD: return PERIOD; break;
        case SDLK_SLASH: return SLASH; break;
        case SDLK_COLON: return COLON; break;
        case SDLK_SEMICOLON: return SEMICOLON; break;
        case SDLK_LESS: return LESS; break;
        case SDLK_EQUALS: return EQUALS; break;
        case SDLK_GREATER: return GREATER; break;
        case SDLK_QUESTION: return QUESTION; break;
        case SDLK_AT: return AT; break;
        case SDLK_LEFTBRACKET: return LEFTBRACKET; break;
        case SDLK_BACKSLASH: return BACKSLASH; break;
        case SDLK_RIGHTBRACKET: return RIGHTBRACKET; break;
        case SDLK_CARET: return CARET; break;
        case SDLK_UNDERSCORE: return UNDERSCORE; break;
        case SDLK_BACKQUOTE: return BACKQUOTE; break;
        case SDLK_a: return a; break;
        case SDLK_b: return b; break;
        case SDLK_c: return c; break;
        case SDLK_d: return d; break;
        case SDLK_e: return e; break;
        case SDLK_f: return f; break;
        case SDLK_g: return g; break;
        case SDLK_h: return h; break;
        case SDLK_i: return i; break;
        case SDLK_j: return j; break;
        case SDLK_k: return k; break;
        case SDLK_l: return l; break;
        case SDLK_m: return m; break;
        case SDLK_n: return n; break;
        case SDLK_o: return o; break;
        case SDLK_p: return p; break;
        case SDLK_r: return r; break;
        case SDLK_s: return s; break;
        case SDLK_t: return t; break;
        case SDLK_u: return u; break;
        case SDLK_v: return v; break;
        case SDLK_w: return w; break;
        case SDLK_x: return x; break;
        case SDLK_y: return y; break;
        case SDLK_z: return z; break;
        case SDLK_CAPSLOCK: return CAPSLOCK; break;
        case SDLK_F1: return F1; break;
        case SDLK_F2: return F2; break;
        case SDLK_F3: return F3; break;
        case SDLK_F4: return F4; break;
        case SDLK_F5: return F5; break;
        case SDLK_F6: return F6; break;
        case SDLK_F7: return F7; break;
        case SDLK_F8: return F8; break;
        case SDLK_F9: return F9; break;
        case SDLK_F10: return F10; break;
        case SDLK_F11: return F11; break;
        case SDLK_F12: return F12; break;
        case SDLK_PRINTSCREEN: return PRINTSCREEN; break;
        case SDLK_SCROLLLOCK: return SCROLLLOCK; break;
        case SDLK_PAUSE: return PAUSE; break;
        case SDLK_INSERT: return INSERT; break;
        case SDLK_HOME: return HOME; break;
        case SDLK_PAGEUP: return PAGEUP; break;
        case SDLK_DELETE: return DELETE; break;
        case SDLK_END: return END; break;
        case SDLK_PAGEDOWN: return PAGEDOWN; break;
        case SDLK_NUMLOCKCLEAR: return NUMLOCKCLEAR; break;
        case SDLK_KP_DIVIDE: return KP_DIVIDE; break;
        case SDLK_KP_MULTIPLY: return KP_MULTIPLY; break;
        case SDLK_KP_MINUS: return KP_MINUS; break;
        case SDLK_KP_PLUS: return KP_PLUS; break;
        case SDLK_KP_ENTER: return KP_ENTER; break;
        case SDLK_KP_1: return KP_1; break;
        case SDLK_KP_2: return KP_2; break;
        case SDLK_KP_3: return KP_3; break;
        case SDLK_KP_4: return KP_4; break;
        case SDLK_KP_5: return KP_5; break;
        case SDLK_KP_6: return KP_6; break;
        case SDLK_KP_7: return KP_7; break;
        case SDLK_KP_8: return KP_8; break;
        case SDLK_KP_9: return KP_9; break;
        case SDLK_KP_0: return KP_0; break;
        case SDLK_KP_PERIOD: return KP_PERIOD; break;
        case SDLK_APPLICATION: return APPLICATION; break;
        case SDLK_POWER: return POWER; break;
        case SDLK_KP_EQUALS: return KP_EQUALS; break;
        case SDLK_F13: return F13; break;
        case SDLK_F14: return F14; break;
        case SDLK_F15: return F15; break;
        case SDLK_F16: return F16; break;
        case SDLK_F17: return F17; break;
        case SDLK_F18: return F18; break;
        case SDLK_F19: return F19; break;
        case SDLK_F20: return F20; break;
        case SDLK_F21: return F21; break;
        case SDLK_F22: return F22; break;
        case SDLK_F23: return F23; break;
        case SDLK_F24: return F24; break;
        case SDLK_EXECUTE: return EXECUTE; break;
        case SDLK_HELP: return HELP; break;
        case SDLK_MENU: return MENU; break;
        case SDLK_SELECT: return SELECT; break;
        case SDLK_STOP: return STOP; break;
        case SDLK_AGAIN: return AGAIN; break;
        case SDLK_UNDO: return UNDO; break;
        case SDLK_CUT: return CUT; break;
        case SDLK_COPY: return COPY; break;
        case SDLK_PASTE: return PASTE; break;
        case SDLK_FIND: return FIND; break;
        case SDLK_MUTE: return MUTE; break;
        case SDLK_VOLUMEUP: return VOLUMEUP; break;
        case SDLK_VOLUMEDOWN: return VOLUMEDOWN; break;
        case SDLK_KP_COMMA: return COMMA; break;
        case SDLK_KP_EQUALSAS400: return KP_EQUALSAS400; break;
        case SDLK_ALTERASE: return ALTERASE; break;
        case SDLK_SYSREQ: return SYSREQ; break;
        case SDLK_CANCEL: return CANCEL; break;
        case SDLK_PRIOR: return PRIOR; break;
        case SDLK_RETURN2: return RETURN2; break;
        case SDLK_SEPARATOR: return SEPARATOR; break;
        case SDLK_OUT: return OUT; break;
        case SDLK_OPER: return OPER; break;
        case SDLK_CLEARAGAIN: return CLEARAGAIN; break;
        case SDLK_CRSEL: return CRSEL; break;
        case SDLK_EXSEL: return EXSEL; break;
        case SDLK_KP_00: return KP_00; break;
        case SDLK_KP_000: return KP_000; break;
        case SDLK_DECIMALSEPARATOR: return DECIMALSEPARATOR; break;
        case SDLK_CURRENCYUNIT: return CURRENCYUNIT; break;
        case SDLK_CURRENCYSUBUNIT: return CURRENCYUNIT; break;
        case SDLK_KP_LEFTBRACE: return KP_LEFTBRACE; break;
        case SDLK_KP_RIGHTBRACE: return KP_RIGHTBRACE; break;
        case SDLK_KP_LEFTPAREN: return KP_LEFTPAREN; break;
        case SDLK_KP_RIGHTPAREN: return KP_RIGHTPAREN; break;
        case SDLK_KP_TAB: return KP_TAB; break;
        case SDLK_KP_BACKSPACE: return KP_BACKSPACE; break;
        case SDLK_KP_A: return KP_A; break;
        case SDLK_KP_B: return KP_B; break;
        case SDLK_KP_C: return KP_C; break;
        case SDLK_KP_D: return KP_D; break;
        case SDLK_KP_E: return KP_E; break;
        case SDLK_KP_F: return KP_F; break;
        case SDLK_KP_XOR: return KP_XOR; break;
        case SDLK_KP_POWER: return KP_POWER; break;
        case SDLK_KP_PERCENT: return KP_PERCENT; break;
        case SDLK_KP_LESS: return KP_LESS; break;
        case SDLK_KP_GREATER: return KP_GREATER; break;
        case SDLK_KP_AMPERSAND: return KP_AMPERSAND; break;
        case SDLK_KP_DBLAMPERSAND: return KP_DBLAMPERSAND; break;
        case SDLK_KP_VERTICALBAR: return KP_VERTICALBAR; break;
        case SDLK_KP_DBLVERTICALBAR: return KP_DBLVERTICALBAR; break;
        case SDLK_KP_COLON: return KP_COLON; break;
        case SDLK_KP_HASH: return ; break;
        case SDLK_KP_SPACE: return ; break;
        case SDLK_KP_AT: return ; break;
        case SDLK_KP_EXCLAM: return ; break;
        case SDLK_KP_MEMSTORE: return ; break;
        case SDLK_KP_MEMRECALL: return ; break;
        case SDLK_KP_MEMCLEAR: return ; break;
        case SDLK_KP_MEMADD: return ; break;
        case SDLK_KP_MEMSUBTRACT: return ; break;
        case SDLK_KP_MEMMULTIPLY: return ; break;
        case SDLK_KP_MEMDIVIDE: return ; break;
        case SDLK_KP_PLUSMINUS: return ; break;
        case SDLK_KP_CLEAR: return ; break;
        case SDLK_KP_CLEARENTRY: return ; break;
        case SDLK_KP_BINARY: return ; break;
        case SDLK_KP_OCTAL: return ; break;
        case SDLK_KP_DECIMAL: return ; break;
        case SDLK_KP_HEXADECIMAL: return ; break;
	case SDLK_LCTRL: return ; break;
        


        default:
            break;
        }
        break;
    
    }
}
