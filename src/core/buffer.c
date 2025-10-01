#include "core/buffer.h"

#include <stdlib.h>
#include <string.h>

#include "core/state.h"

void Buffer_InsertChar(size_t pos, wchar_t c) {
    wchar_t* p = state.buffer;
    size_t len = 0;

    while (*p) {
        p++;
        len++;
    }

    state.buffer = realloc(state.buffer, (len + 1 + 1) * sizeof(wchar_t));
    memmove(
        state.buffer + pos + 1,
        state.buffer + pos,
        (len + 1 - pos) * sizeof(wchar_t)
    );
    state.buffer[pos] = c;
}