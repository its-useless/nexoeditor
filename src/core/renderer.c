#include "core/renderer.h"

#include <ncurses.h>

#include "core/buffer.h"
#include "core/state.h"

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

        if (line >= s_renderer.text_off_y) {
            mvprintw(
                line + 1 - (size_t)s_renderer.text_off_y,
                line_char,
                "%lc",
                *c
            );
        }

        if (line >= s_renderer.text_off_y + getmaxy(stdscr)) {
            break;
        }

        line_char++;
        c++;
    }
}
