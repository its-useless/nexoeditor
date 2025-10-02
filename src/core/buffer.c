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
    if (pos > len)
        return;

    state.buffer = realloc(state.buffer, (len + 1 + 1) * sizeof(wchar_t));
    memmove(
        state.buffer + pos + 1,
        state.buffer + pos,
        (len + 1 - pos) * sizeof(wchar_t)
    );
    state.buffer[pos] = c;
}

void Buffer_RemoveChar(size_t pos) {
    wchar_t* p = state.buffer;
    size_t len = 0;

    while (*p) {
        p++;
        len++;
    }
    if (pos > len)
        return;
    if (pos == len) {
        state.buffer = realloc(state.buffer, (len) * sizeof(wchar_t));
        state.buffer[len - 1] = 0;
        return;
    }

    void* dest = state.buffer + pos;
    void* src = state.buffer + pos + 1;
    size_t size = (len - pos - 1) * sizeof(wchar_t);
    memmove(dest, src, size);
    state.buffer = realloc(state.buffer, (len) * sizeof(wchar_t));
    state.buffer[len - 1] = 0;
}
