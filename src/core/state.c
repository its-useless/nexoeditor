#include "core/state.h"

#include "core/mem.h"

State state = {0};

void State_Free() {
    if (state.buffer)
        xfree(state.buffer);
    if (state.filename)
        xfree(state.filename);
}