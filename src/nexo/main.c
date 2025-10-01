#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/input.h"
#include "core/mem.h"
#include "core/renderer.h"
#include "core/state.h"

int main() {
    buffer = xstralloc("00\n11\n22\n33");

    initscr();
    keypad(stdscr, TRUE);
    set_escdelay(0);

    state.running = TRUE;
    while (state.running) {
        int k;

        clear();

        mvprintw(0, 0, "nexo");
        move(0, 0);

        Renderer_RenderBuffer();
        move(cursor.y + 1, cursor.x);

        refresh();

        k = getch();
        if (!Cursor_HandleKeypress(k))
            Input_HandleKeypress(k);
    }
    endwin();

    xfree(buffer);
    return 0;
}