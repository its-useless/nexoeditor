#include "renderer.h"

#include <ncurses.h>

#include "buffer.h"

Renderer renderer = {0};

void Renderer_RenderBuffer() {
    size_t i, line = 0, line_char = 0;
    for (i = 0; i < buffer_len; i++) {
        char c = buffer[i];
        if (c == 0)
            break;
        if (c == '\n') {
            line++;
            line_char = 0;
            continue;
        }

        mvprintw(line + 1, line_char, "%c", c);

        line_char++;
    }
}