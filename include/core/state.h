#if !defined(CORE_STATE_H)
    #define CORE_STATE_H
    #include <curses.h>

typedef struct State {
    bool running;
} State;

extern State state;

#endif
