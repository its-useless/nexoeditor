#include "core/renderer.h"

#include <ncurses.h>

#include "core/buffer.h"
#include "core/state.h"

Renderer renderer = {0};

void Renderer_RenderBuffer(void) {
    size_t line = 0, line_char = 0;
    wchar_t* c = state.buffer;
    while (*c) {
        if (*c == L'\n') {
            line++;
            line_char = 0;
            c++;
            continue;
        }

        if (line >= renderer.text_off_y) {
            mvprintw(
                line + 1 - (size_t)renderer.text_off_y,
                line_char,
                "%lc",
                *c
            );
        }

        line_char++;
        c++;
    }
}
