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
    size_t i, line_idx, line_chars = 0;
    size_t lines = 0;
    char* line = NULL;

    for (i = 0; i < buffer_len; i++) {
        if (buffer[i] == '\n')
            lines++;

        if (lines >= cursor.y && !line) {
            line = buffer + i + 1;
            if (lines == 0)
                line--;
        }
    }

    if (cursor.y < 0)
        cursor.y = 0;
    if (cursor.y > lines) {
        cursor.y = lines;
    }

    if (line) {
        char* c = line;
        for (;;) {
            if (*c == '\n' || *c == 0) {
                break;
            }
            c++;
            line_chars++;
        }

        if (cursor.x < 0)
            cursor.x = 0;
        if (cursor.x >= line_chars) {
            cursor.x = line_chars;
        }
    } else {
        cursor.x = 0;
    }
}