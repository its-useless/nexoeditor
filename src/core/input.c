#include "core/input.h"

#include <curses.h>

bool Input_IsTextChar(int k) {
    return (k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z');
}

bool Input_HandleKeypress(int k) {
    if (Input_IsTextChar(k)) {
        // input text
        return TRUE;
    }
    return FALSE;
}