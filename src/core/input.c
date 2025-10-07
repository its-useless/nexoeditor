#include "core/input.h"

#include <curses.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/state.h"

bool Input_IsTextChar(wchar_t k);
void Input_InputChar(wchar_t k);
void Input_RemoveChar();

bool Input_IsTextChar(wchar_t k) {
    size_t i, ranges_total;
#define RANGE(from, to) {L##from, L##to}
#define RANGE_CHAR(char) \
    { L##char, L##char }
    const wchar_t ranges[][2] = {
        RANGE_CHAR('!'),  RANGE('a', 'z'),  RANGE('A', 'Z'),  RANGE('а', 'я'),
        RANGE('А', 'Я'),  RANGE('0', '9'),  RANGE_CHAR('+'),  RANGE_CHAR('-'),
        RANGE_CHAR('*'),  RANGE_CHAR('/'),  RANGE_CHAR('='),  RANGE_CHAR('('),
        RANGE_CHAR(')'),  RANGE_CHAR('['),  RANGE_CHAR(']'),  RANGE_CHAR('{'),
        RANGE_CHAR('}'),  RANGE_CHAR(';'),  RANGE_CHAR(' '),  RANGE_CHAR('\n'),
        RANGE_CHAR('\t'), RANGE_CHAR(','),  RANGE_CHAR('#'),  RANGE_CHAR('<'),
        RANGE_CHAR('>'),  RANGE_CHAR('\"'), RANGE_CHAR('\''), RANGE_CHAR('%'),
        RANGE_CHAR('.'),  RANGE_CHAR('/'),  RANGE_CHAR('\\'), RANGE_CHAR('@'),
        RANGE_CHAR('$'),  RANGE_CHAR('%'),  RANGE_CHAR('^'),  RANGE_CHAR(':'),
        RANGE_CHAR('*'),  RANGE_CHAR('_'),  RANGE_CHAR('?'),  RANGE_CHAR('`'),
        RANGE_CHAR('~'),  RANGE_CHAR('|'),

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
    if (k == L'\t') {
        for (int i = 0; i < 4; i++) {
            Input_InputChar(' ');
        }
        return;
    }
    wchar_t *c, *pos = NULL;
    size_t line = 0, line_char = 0, pos_index = 0;

    /* find our pos in text */
    c = state.buffer;
    for (;;) {
        if (line_char == s_cursor.x && line == s_cursor.y) {
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
            s_cursor.x = 0;
        }
    }
}

void Input_RemoveChar() {
    if (s_cursor.x == 0 && s_cursor.y == 0)
        return;

    wchar_t *c, *pos = NULL;
    size_t line = 0, line_char = 0, pos_index = 0;

    /* find our pos in text */
    c = state.buffer;
    for (;;) {
        if (line_char == s_cursor.x && line == s_cursor.y) {
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
        bool newline = *(pos - 1) == '\n';
        Buffer_RemoveChar(pos_index - 1);
        Cursor_MoveLeft();
        if (newline) {
            size_t len = wcslen(state.buffer) + 1;
            if (pos_index != len) {
                Cursor_MoveUp();
            }
            s_cursor.x = INT32_MAX;
            Cursor_EnsurePosition();
        }
    }
}

bool Input_HandleKeypress(wchar_t k) {
    switch (k) {
        case 27: {
            state.running = FALSE;
            break;
        }
        case KEY_BACKSPACE:
            Input_RemoveChar();
            break;
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
