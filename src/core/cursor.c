#include "core/cursor.h"

#include <curses.h>

#include "core/buffer.h"
#include "core/renderer.h"
#include "core/state.h"

void Cursor_MoveUp(void) {
    s_cursor.y--;
    Cursor_EnsurePosition();
    if ((s_cursor.y - s_renderer.text_off_y) < 0) {
        s_renderer.text_off_y--;
    }
}

void Cursor_MoveDown(void) {
    s_cursor.y++;
    Cursor_EnsurePosition();
    if ((s_cursor.y - s_renderer.text_off_y) >= (getmaxy(stdscr) - 1)) {
        s_renderer.text_off_y++;
    }
}

void Cursor_MoveLeft(void) {
    s_cursor.x--;
    Cursor_EnsurePosition();
}

void Cursor_MoveRight(void) {
    s_cursor.x++;
    Cursor_EnsurePosition();
}

bool Cursor_HandleKeypress(wchar_t key) {
    switch (key) {
        case KEY_LEFT:
            Cursor_MoveLeft();
            return TRUE;
        case KEY_DOWN:
            Cursor_MoveDown();
            return TRUE;
        case KEY_UP:
            Cursor_MoveUp();
            return TRUE;
        case KEY_RIGHT:
            Cursor_MoveRight();
            return TRUE;
        default:
            break;
    }
    return FALSE;
}

void Cursor_EnsurePosition(void) {
    size_t lines = 0;
    wchar_t *line = NULL, *c = state.buffer;

    while (*c) {
        if (lines == s_cursor.y && !line)
            line = c;

        if (*c == '\n') {
            lines++;
            c++;
            continue;
        }

        if (lines == s_cursor.y && !line)
            line = c;
        c++;
    }

    if (s_cursor.y < 0)
        s_cursor.y = 0;
    if (s_cursor.y >= lines)
        s_cursor.y = lines;
    if (s_cursor.x < 0)
        s_cursor.x = 0;

    if (line) {
        size_t chars = 0;
        c = line;
        while (*c) {
            if (*c == '\n') {
                break;
            }
            chars++;
            c++;
        }

        if (s_cursor.x > chars)
            s_cursor.x = chars;
    } else {
        s_cursor.x = 0;
    }
}
