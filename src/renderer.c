#include "renderer.h"

#include <ncurses.h>

#include "buffer.h"

Renderer renderer = {0};

void Renderer_RenderBuffer() {
    size_t i, line = 0, line_char = 0;
    char* c = buffer;
    while (*c) {
        if (*c == '\n') {
            line++;
            line_char = 0;
            c++;
            continue;
        }

        mvprintw(line + 1, line_char, "%c", *c);

        line_char++;
        c++;
    }
}