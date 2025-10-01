#if !defined(CORE_STATE_H)
    #define CORE_STATE_H
    #include <curses.h>
    #include <wchar.h>

typedef struct State {
    wchar_t* buffer;
    bool running;
} State;

extern State state;

#endif
