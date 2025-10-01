#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/input.h"
#include "core/mem.h"
#include "core/renderer.h"

int main() {
    buffer = xstralloc("Hello, World!\nline1\nline2\nline3");

    initscr();
    keypad(stdscr, TRUE);

    for (;;) {
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

        if (k == 'q')
            break;
    }
    endwin();

    xfree(buffer);
    return 0;
}