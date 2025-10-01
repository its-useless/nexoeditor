#include "core/input.h"

#include <curses.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/state.h"

bool Input_IsTextChar(int k) {
    return (k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') || k == '!'
        || k == '.' || k == '-' || k == '+' || k == ' ';
}

void Input_InputChar(int k) {
    wchar_t *c, *pos = NULL;
    size_t line = 0, line_char = 0, pos_index = 0;

    /* find our pos in text */
    c = state.buffer;
    for (;;) {
        if (line_char == cursor.x && line == cursor.y) {
            pos = c;
            break;
        }
        if (!*c)
            break;

        if (*c == '\n') {
            line_char = 0;
            line++;
        } else {
            line_char++;
        }
        c++;
    }

    if (pos) {
        pos_index = pos - state.buffer;
        Buffer_InsertChar(pos_index, (char)k);
        Cursor_MoveRight();
    }
}

bool Input_HandleKeypress(wchar_t k) {
    switch (k) {
        case 27: {
            state.running = FALSE;
            break;
        }
        default:
            if (Input_IsTextChar(k)) {
                /* input text */
                Input_InputChar(k);
                return TRUE;
            }
            break;
    }
    return FALSE;
}