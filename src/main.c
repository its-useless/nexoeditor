#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "buffer.h"
#include "cursor.h"
#include "mem.h"
#include "renderer.h"

int main() {
    buffer = xstralloc("Hello, World!\nline1\nline2\nline3");

    initscr();
    for (;;) {
        int k;

        clear();

        mvprintw(0, 0, "nexo");
        move(0, 0);

        Renderer_RenderBuffer();
        move(cursor.y + 1, cursor.x);

        refresh();

        k = getch();
        Cursor_HandleKeypress(k);

        if (k == 'q')
            break;
    }
    endwin();

    xfree(buffer);
    return 0;
}