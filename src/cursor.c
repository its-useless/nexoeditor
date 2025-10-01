#include "cursor.h"

#include "buffer.h"

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
    cursor.x++;
    Cursor_EnsurePosition();
}

void Cursor_MoveRight() {
    cursor.x--;
    Cursor_EnsurePosition();
}

void Cursor_HandleKeypress(int key) {
    switch (key) {
        case 'h':
            Cursor_MoveRight();
            break;
        case 'j':
            Cursor_MoveDown();
            break;
        case 'k':
            Cursor_MoveUp();
            break;
        case 'l':
            Cursor_MoveLeft();
            break;
        default:
            break;
    }
}

void Cursor_EnsurePosition() {
    size_t lines = 0;
    char *line = NULL, *c = buffer;

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