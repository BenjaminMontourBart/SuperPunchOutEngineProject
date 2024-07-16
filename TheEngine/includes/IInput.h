#pragma once

namespace Homer 
{
    enum MyKey
    {
        MyKey_UNKNOWN = 0,

        /**
         *  \name Usage page 0x07
         *
         *  These values are from usage page 0x07 (USB keyboard page).
         */
         /* @{ */

        MyKey_A = 4,
        MyKey_B = 5,
        MyKey_C = 6,
        MyKey_D = 7,
        MyKey_E = 8,
        MyKey_F = 9,
        MyKey_G = 10,
        MyKey_H = 11,
        MyKey_I = 12,
        MyKey_J = 13,
        MyKey_K = 14,
        MyKey_L = 15,
        MyKey_M = 16,
        MyKey_N = 17,
        MyKey_O = 18,
        MyKey_P = 19,
        MyKey_Q = 20,
        MyKey_R = 21,
        MyKey_S = 22,
        MyKey_T = 23,
        MyKey_U = 24,
        MyKey_V = 25,
        MyKey_W = 26,
        MyKey_X = 27,
        MyKey_Y = 28,
        MyKey_Z = 29,

        MyKey_1 = 30,
        MyKey_2 = 31,
        MyKey_3 = 32,
        MyKey_4 = 33,
        MyKey_5 = 34,
        MyKey_6 = 35,
        MyKey_7 = 36,
        MyKey_8 = 37,
        MyKey_9 = 38,
        MyKey_0 = 39,

        MyKey_RETURN = 40,
        MyKey_ESCAPE = 41,
        MyKey_BACKSPACE = 42,
        MyKey_TAB = 43,
        MyKey_SPACE = 44,

        MyKey_MINUS = 45,
        MyKey_EQUALS = 46,
        MyKey_LEFTBRACKET = 47,
        MyKey_RIGHTBRACKET = 48,
        MyKey_BACKSLASH = 49, /**< Located at the lower left of the return
                                      *   key on ISO keyboards and at the right end
                                      *   of the QWERTY row on ANSI keyboards.
                                      *   Produces REVERSE SOLIDUS (backslash) and
                                      *   VERTICAL LINE in a US layout, REVERSE
                                      *   SOLIDUS and VERTICAL LINE in a UK Mac
                                      *   layout, NUMBER SIGN and TILDE in a UK
                                      *   Windows layout, DOLLAR SIGN and POUND SIGN
                                      *   in a Swiss German layout, NUMBER SIGN and
                                      *   APOSTROPHE in a German layout, GRAVE
                                      *   ACCENT and POUND SIGN in a French Mac
                                      *   layout, and ASTERISK and MICRO SIGN in a
                                      *   French Windows layout.
                                      */
        MyKey_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                      *   instead of 49 for the same key, but all
                                      *   OSes I've seen treat the two codes
                                      *   identically. So, as an implementor, unless
                                      *   your keyboard generates both of those
                                      *   codes and your OS treats them differently,
                                      *   you should generate MyKey_BACKSLASH
                                      *   instead of this code. As a user, you
                                      *   should not rely on this code because SDL
                                      *   will never generate it with most (all?)
                                      *   keyboards.
                                      */
        MyKey_SEMICOLON = 51,
        MyKey_APOSTROPHE = 52,
        MyKey_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                                  *   and ISO keyboards). Produces GRAVE ACCENT and
                                  *   TILDE in a US Windows layout and in US and UK
                                  *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                  *   and NOT SIGN in a UK Windows layout, SECTION
                                  *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                  *   layouts on ISO keyboards, SECTION SIGN and
                                  *   DEGREE SIGN in a Swiss German layout (Mac:
                                  *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                  *   DEGREE SIGN in a German layout (Mac: only on
                                  *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                  *   French Windows layout, COMMERCIAL AT and
                                  *   NUMBER SIGN in a French Mac layout on ISO
                                  *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                  *   SIGN in a Swiss German, German, or French Mac
                                  *   layout on ANSI keyboards.
                                  */
        MyKey_COMMA = 54,
        MyKey_PERIOD = 55,
        MyKey_SLASH = 56,

        MyKey_CAPSLOCK = 57,

        MyKey_F1 = 58,
        MyKey_F2 = 59,
        MyKey_F3 = 60,
        MyKey_F4 = 61,
        MyKey_F5 = 62,
        MyKey_F6 = 63,
        MyKey_F7 = 64,
        MyKey_F8 = 65,
        MyKey_F9 = 66,
        MyKey_F10 = 67,
        MyKey_F11 = 68,
        MyKey_F12 = 69,

        MyKey_PRINTSCREEN = 70,
        MyKey_SCROLLLOCK = 71,
        MyKey_PAUSE = 72,
        MyKey_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                       does send code 73, not 117) */
        MyKey_HOME = 74,
        MyKey_PAGEUP = 75,
        MyKey_DELETE = 76,
        MyKey_END = 77,
        MyKey_PAGEDOWN = 78,
        MyKey_RIGHT = 79,
        MyKey_LEFT = 80,
        MyKey_DOWN = 81,
        MyKey_UP = 82,

        MyKey_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                         */
        MyKey_KP_DIVIDE = 84,
        MyKey_KP_MULTIPLY = 85,
        MyKey_KP_MINUS = 86,
        MyKey_KP_PLUS = 87,
        MyKey_KP_ENTER = 88,
        MyKey_KP_1 = 89,
        MyKey_KP_2 = 90,
        MyKey_KP_3 = 91,
        MyKey_KP_4 = 92,
        MyKey_KP_5 = 93,
        MyKey_KP_6 = 94,
        MyKey_KP_7 = 95,
        MyKey_KP_8 = 96,
        MyKey_KP_9 = 97,
        MyKey_KP_0 = 98,
        MyKey_KP_PERIOD = 99,

        MyKey_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                            *   keyboards have over ANSI ones,
                                            *   located between left shift and Y.
                                            *   Produces GRAVE ACCENT and TILDE in a
                                            *   US or UK Mac layout, REVERSE SOLIDUS
                                            *   (backslash) and VERTICAL LINE in a
                                            *   US or UK Windows layout, and
                                            *   LESS-THAN SIGN and GREATER-THAN SIGN
                                            *   in a Swiss German, German, or French
                                            *   layout. */
        MyKey_APPLICATION = 101, /**< windows contextual menu, compose */
        MyKey_POWER = 102, /**< The USB document says this is a status flag,
                                   *   not a physical key - but some Mac keyboards
                                   *   do have a power key. */
        MyKey_KP_EQUALS = 103,
        MyKey_F13 = 104,
        MyKey_F14 = 105,
        MyKey_F15 = 106,
        MyKey_F16 = 107,
        MyKey_F17 = 108,
        MyKey_F18 = 109,
        MyKey_F19 = 110,
        MyKey_F20 = 111,
        MyKey_F21 = 112,
        MyKey_F22 = 113,
        MyKey_F23 = 114,
        MyKey_F24 = 115,
        MyKey_EXECUTE = 116,
        MyKey_HELP = 117,    /**< AL Integrated Help Center */
        MyKey_MENU = 118,    /**< Menu (show menu) */
        MyKey_SELECT = 119,
        MyKey_STOP = 120,    /**< AC Stop */
        MyKey_AGAIN = 121,   /**< AC Redo/Repeat */
        MyKey_UNDO = 122,    /**< AC Undo */
        MyKey_CUT = 123,     /**< AC Cut */
        MyKey_COPY = 124,    /**< AC Copy */
        MyKey_PASTE = 125,   /**< AC Paste */
        MyKey_FIND = 126,    /**< AC Find */
        MyKey_MUTE = 127,
        MyKey_VOLUMEUP = 128,
        MyKey_VOLUMEDOWN = 129,
        /* not sure whether there's a reason to enable these */
        /*     MyKey_LOCKINGCAPSLOCK = 130,  */
        /*     MyKey_LOCKINGNUMLOCK = 131, */
        /*     MyKey_LOCKINGSCROLLLOCK = 132, */
        MyKey_KP_COMMA = 133,
        MyKey_KP_EQUALSAS400 = 134,

        MyKey_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                                footnotes in USB doc */
        MyKey_INTERNATIONAL2 = 136,
        MyKey_INTERNATIONAL3 = 137, /**< Yen */
        MyKey_INTERNATIONAL4 = 138,
        MyKey_INTERNATIONAL5 = 139,
        MyKey_INTERNATIONAL6 = 140,
        MyKey_INTERNATIONAL7 = 141,
        MyKey_INTERNATIONAL8 = 142,
        MyKey_INTERNATIONAL9 = 143,
        MyKey_LANG1 = 144, /**< Hangul/English toggle */
        MyKey_LANG2 = 145, /**< Hanja conversion */
        MyKey_LANG3 = 146, /**< Katakana */
        MyKey_LANG4 = 147, /**< Hiragana */
        MyKey_LANG5 = 148, /**< Zenkaku/Hankaku */
        MyKey_LANG6 = 149, /**< reserved */
        MyKey_LANG7 = 150, /**< reserved */
        MyKey_LANG8 = 151, /**< reserved */
        MyKey_LANG9 = 152, /**< reserved */

        MyKey_ALTERASE = 153,    /**< Erase-Eaze */
        MyKey_SYSREQ = 154,
        MyKey_CANCEL = 155,      /**< AC Cancel */
        MyKey_CLEAR = 156,
        MyKey_PRIOR = 157,
        MyKey_RETURN2 = 158,
        MyKey_SEPARATOR = 159,
        MyKey_OUT = 160,
        MyKey_OPER = 161,
        MyKey_CLEARAGAIN = 162,
        MyKey_CRSEL = 163,
        MyKey_EXSEL = 164,

        MyKey_KP_00 = 176,
        MyKey_KP_000 = 177,
        MyKey_THOUSANDSSEPARATOR = 178,
        MyKey_DECIMALSEPARATOR = 179,
        MyKey_CURRENCYUNIT = 180,
        MyKey_CURRENCYSUBUNIT = 181,
        MyKey_KP_LEFTPAREN = 182,
        MyKey_KP_RIGHTPAREN = 183,
        MyKey_KP_LEFTBRACE = 184,
        MyKey_KP_RIGHTBRACE = 185,
        MyKey_KP_TAB = 186,
        MyKey_KP_BACKSPACE = 187,
        MyKey_KP_A = 188,
        MyKey_KP_B = 189,
        MyKey_KP_C = 190,
        MyKey_KP_D = 191,
        MyKey_KP_E = 192,
        MyKey_KP_F = 193,
        MyKey_KP_XOR = 194,
        MyKey_KP_POWER = 195,
        MyKey_KP_PERCENT = 196,
        MyKey_KP_LESS = 197,
        MyKey_KP_GREATER = 198,
        MyKey_KP_AMPERSAND = 199,
        MyKey_KP_DBLAMPERSAND = 200,
        MyKey_KP_VERTICALBAR = 201,
        MyKey_KP_DBLVERTICALBAR = 202,
        MyKey_KP_COLON = 203,
        MyKey_KP_HASH = 204,
        MyKey_KP_SPACE = 205,
        MyKey_KP_AT = 206,
        MyKey_KP_EXCLAM = 207,
        MyKey_KP_MEMSTORE = 208,
        MyKey_KP_MEMRECALL = 209,
        MyKey_KP_MEMCLEAR = 210,
        MyKey_KP_MEMADD = 211,
        MyKey_KP_MEMSUBTRACT = 212,
        MyKey_KP_MEMMULTIPLY = 213,
        MyKey_KP_MEMDIVIDE = 214,
        MyKey_KP_PLUSMINUS = 215,
        MyKey_KP_CLEAR = 216,
        MyKey_KP_CLEARENTRY = 217,
        MyKey_KP_BINARY = 218,
        MyKey_KP_OCTAL = 219,
        MyKey_KP_DECIMAL = 220,
        MyKey_KP_HEXADECIMAL = 221,

        MyKey_LCTRL = 224,
        MyKey_LSHIFT = 225,
        MyKey_LALT = 226, /**< alt, option */
        MyKey_LGUI = 227, /**< windows, command (apple), meta */
        MyKey_RCTRL = 228,
        MyKey_RSHIFT = 229,
        MyKey_RALT = 230, /**< alt gr, option */
        MyKey_RGUI = 231, /**< windows, command (apple), meta */

        MyKey_MODE = 257,    /**< I'm not sure if this is really not covered
                                     *   by any of the above, but since there's a
                                     *   special KMOD_MODE for it I'm adding it here
                                     */

                                     /* @} *//* Usage page 0x07 */

                                     /**
                                      *  \name Usage page 0x0C
                                      *
                                      *  These values are mapped from usage page 0x0C (USB consumer page).
                                      *  See https://usb.org/sites/default/files/hut1_2.pdf
                                      *
                                      *  There are way more keys in the spec than we can represent in the
                                      *  current scancode range, so pick the ones that commonly come up in
                                      *  real world usage.
                                      */
                                      /* @{ */

        MyKey_AUDIONEXT = 258,
        MyKey_AUDIOPREV = 259,
        MyKey_AUDIOSTOP = 260,
        MyKey_AUDIOPLAY = 261,
        MyKey_AUDIOMUTE = 262,
        MyKey_MEDIASELECT = 263,
        MyKey_WWW = 264,             /**< AL Internet Browser */
        MyKey_MAIL = 265,
        MyKey_CALCULATOR = 266,      /**< AL Calculator */
        MyKey_COMPUTER = 267,
        MyKey_AC_SEARCH = 268,       /**< AC Search */
        MyKey_AC_HOME = 269,         /**< AC Home */
        MyKey_AC_BACK = 270,         /**< AC Back */
        MyKey_AC_FORWARD = 271,      /**< AC Forward */
        MyKey_AC_STOP = 272,         /**< AC Stop */
        MyKey_AC_REFRESH = 273,      /**< AC Refresh */
        MyKey_AC_BOOKMARKS = 274,    /**< AC Bookmarks */

        /* @} *//* Usage page 0x0C */

        /**
         *  \name Walther keys
         *
         *  These are values that Christian Walther added (for mac keyboard?).
         */
         /* @{ */

        MyKey_BRIGHTNESSDOWN = 275,
        MyKey_BRIGHTNESSUP = 276,
        MyKey_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                               switch, video mode switch */
        MyKey_KBDILLUMTOGGLE = 278,
        MyKey_KBDILLUMDOWN = 279,
        MyKey_KBDILLUMUP = 280,
        MyKey_EJECT = 281,
        MyKey_SLEEP = 282,           /**< SC System Sleep */

        MyKey_APP1 = 283,
        MyKey_APP2 = 284,

        /* @} *//* Walther keys */

        /**
         *  \name Usage page 0x0C (additional media keys)
         *
         *  These values are mapped from usage page 0x0C (USB consumer page).
         */
         /* @{ */

        MyKey_AUDIOREWIND = 285,
        MyKey_AUDIOFASTFORWARD = 286,

        /* @} *//* Usage page 0x0C (additional media keys) */

        /**
         *  \name Mobile keys
         *
         *  These are values that are often used on mobile phones.
         */
         /* @{ */

        MyKey_SOFTLEFT = 287, /**< Usually situated below the display on phones and
                                          used as a multi-function feature key for selecting
                                          a software defined function shown on the bottom left
                                          of the display. */
        MyKey_SOFTRIGHT = 288, /**< Usually situated below the display on phones and
                                           used as a multi-function feature key for selecting
                                           a software defined function shown on the bottom right
                                           of the display. */
        MyKey_CALL = 289, /**< Used for accepting phone calls. */
        MyKey_ENDCALL = 290, /**< Used for rejecting phone calls. */

        /* @} *//* Mobile keys */

        /* Add any other keys here. */

        MyKey_NUM = 512
    };
    class IInput
    {
    /// <summary>
    /// //////// mes touches
    /// </summary>
    public:
        virtual int IsKeyDown(int key) = 0;

    protected:
        friend class Engine;
        virtual void Update() = 0;
        bool isEnd;
    };
}