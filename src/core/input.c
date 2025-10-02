#include "core/input.h"

#include <curses.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/state.h"

bool Input_IsTextChar(wchar_t k);
void Input_InputChar(wchar_t k);

bool Input_IsTextChar(wchar_t k) {
    size_t i, ranges_total;
    const wchar_t ranges[][2] = {
        {L'a', L'z'},
        {L'A', L'Z'},
        {L'а', L'я'},
        {L'А', L'Я'},
        {L'!', L'!'},
        {L'.', L'.'},
        {L',', L','},
        {L' ', L' '},
        {L'(', L'('},
        {L')', L')'},
        {L'{', L'{'},
        {L'}', L'}'},
        {L'[', L'['},
        {L']', L']'},
        {L'\n', L'\n'},
    };
    ranges_total = sizeof(ranges) / sizeof(ranges[0]);
    for (i = 0; i < ranges_total; i++) {
        const wchar_t* range = ranges[i];
        if (k >= range[0] && k <= range[1]) {
            return true;
        }
    }
    return false;
}

void Input_InputChar(wchar_t k) {
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
        pos_index++;
    }

    if (pos) {
        Buffer_InsertChar(pos_index, k);
        Cursor_MoveRight();
        if (k == L'\n') {
            Cursor_MoveDown();
            cursor.x = 0;
        }
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
