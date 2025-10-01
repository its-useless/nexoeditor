#include "core/cursor.h"

#include <curses.h>

#include "core/buffer.h"
#include "core/state.h"

Cursor cursor = {0};

void Cursor_MoveUp() {
    cursor.y--;
    Cursor_EnsurePosition();
}

void Cursor_MoveDown() {
    cursor.y++;
    Cursor_EnsurePosition();
}

void Cursor_MoveLeft() {
    cursor.x--;
    Cursor_EnsurePosition();
}

void Cursor_MoveRight() {
    cursor.x++;
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

void Cursor_EnsurePosition() {
    size_t lines = 0;
    wchar_t *line = NULL, *c = state.buffer;

    while (*c) {
        if (*c == '\n') {
            lines++;
            c++;
            continue;
        }

        if (lines == cursor.y && !line)
            line = c;
        c++;
    }

    if (cursor.y < 0)
        cursor.y = 0;
    if (cursor.y >= lines)
        cursor.y = lines;
    if (cursor.x < 0)
        cursor.x = 0;

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

        if (cursor.x > chars)
            cursor.x = chars;
    }
}