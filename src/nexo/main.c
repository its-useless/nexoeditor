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

int main() {
    setlocale(LC_ALL, "");

    state.buffer = xstralloc(L"00\n11\n22\n33\nтест киррилицы");

    initscr();
    keypad(stdscr, TRUE);
    set_escdelay(0);

    state.running = TRUE;
    while (state.running) {
        wchar_t k;

        clear();

        mvprintw(0, 0, "nexo");
        move(0, 0);

        Renderer_RenderBuffer();
        move(cursor.y + 1, cursor.x);

        refresh();

        get_wch(&k);
        if (!Cursor_HandleKeypress(k))
            Input_HandleKeypress(k);
    }
    endwin();

    xfree(state.buffer);
    return 0;
}