#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/buffer.h"
#include "core/cursor.h"
#include "core/input.h"
#include "core/mem.h"
#include "core/renderer.h"
#include "core/state.h"

/* ion know where it's defined */
void get_wch(wchar_t*);

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    if (argc >= 2) {
        state.filename = strdup(argv[1]);
        FILE* fp = fopen(state.filename, "r");
        if (!fp) {
            printf("nexo: fopen failed\n");
            return 1;
        }

        /* get file size */
        fseek(fp, 0, SEEK_END);
        size_t size = (size_t)ftell(fp);
        rewind(fp);

        /* read shi */
        char* buf = xmalloc(size + 1);

        size_t read = fread(buf, 1, size, fp);
        buf[read] = L'\0';

        /* convert buffers */
        state.buffer =
            xmalloc_chunk(read, sizeof(wchar_t)); /* allocate new buffer*/
        mbstowcs(state.buffer, buf, read); /* convert char* to wchar_t* */
        xfree(buf);

        fclose(fp);
    } else {
        state.buffer = xstralloc(L"");
    }

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
            s_cursor.y,
            s_cursor.x,
            s_renderer.text_off_y,
            s_renderer.text_off_x,
            getmaxy(stdscr),
            getmaxx(stdscr)
        );
        move(0, 0);

        Renderer_RenderBuffer();
        move(s_cursor.y + 1 - s_renderer.text_off_y, s_cursor.x);

        refresh();

        get_wch(&k);
        if (!Cursor_HandleKeypress(k))
            Input_HandleKeypress(k);
    }
    endwin();

    State_Free();
    return 0;
}
