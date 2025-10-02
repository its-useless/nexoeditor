#if !defined(CORE_STATE_H)
    #define CORE_STATE_H
    #include <curses.h>
    #include <wchar.h>

    #include "core/cursor.h"
    #include "core/renderer.h"

typedef struct State {
    wchar_t* buffer;
    bool running;
    Cursor cursor;
    Renderer renderer;
    char* filename;
} State;

extern State state;

void State_Free();

    #define s_renderer state.renderer
    #define s_cursor state.cursor
    #define s_buffer state.buffer

#endif
