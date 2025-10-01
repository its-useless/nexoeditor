#include "core/buffer.h"

#include <stdlib.h>
#include <string.h>

#include "core/state.h"

void Buffer_InsertChar(size_t pos, char c) {
    char* p = state.buffer;
    size_t len = 0;

    while (*p) {
        p++;
        len++;
    }

    state.buffer = realloc(
        state.buffer,
        len + 1
            + 1 /* one for the new char one for the null byte (isn't included in len) */
    );
    memmove(state.buffer + pos + 1, state.buffer + pos, len + 1 - pos);
    state.buffer[pos] = c;
}