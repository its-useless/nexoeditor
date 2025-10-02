#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/input.h"
#include "core/mem.h"
#include "core/renderer.h"
#include "core/state.h"

/* ion know where it's defined */
void get_wch(wchar_t*);

int main(void) {
    setlocale(LC_ALL, "");

    state.buffer = xstralloc(L"01\n02\n");

    initscr();
    keypad(stdscr, TRUE);
    set_escdelay(0);

    state.running = TRUE;
    while (state.running) {
        wchar_t k;

        clear();

        mvprintw(
            0,
            0,
            "nexo (cursor: %d %d) (text off: %d %d) (max: %d %d)",
            cursor.y,
            cursor.x,
            renderer.text_off_y,
            renderer.text_off_x,
            getmaxy(stdscr),
            getmaxx(stdscr)
        );
        move(0, 0);

        Renderer_RenderBuffer();
        move(cursor.y + 1 - renderer.text_off_y, cursor.x);

        refresh();

        get_wch(&k);
        if (!Cursor_HandleKeypress(k))
            Input_HandleKeypress(k);
    }
    endwin();

    xfree(state.buffer);
    return 0;
}
