#include "core/buffer.h"

#include <stdlib.h>
#include <string.h>

#include "core/state.h"

void Buffer_InsertChar(size_t pos, wchar_t c) {
    wchar_t* p = s_buffer;
    size_t len = 0;

    while (*p) {
        p++;
        len++;
    }
    if (pos > len)
        return;

    s_buffer = realloc(s_buffer, (len + 1 + 1) * sizeof(wchar_t));
    memmove(
        s_buffer + pos + 1,
        s_buffer + pos,
        (len + 1 - pos) * sizeof(wchar_t)
    );
    s_buffer[pos] = c;
}

void Buffer_RemoveChar(size_t pos) {
    wchar_t* p = s_buffer;
    size_t len = 0;

    while (*p) {
        p++;
        len++;
    }
    if (pos > len)
        return;
    if (pos == len) {
        s_buffer = realloc(s_buffer, (len) * sizeof(wchar_t));
        s_buffer[len - 1] = 0;
        return;
    }

    void* dest = s_buffer + pos;
    void* src = s_buffer + pos + 1;
    size_t size = (len - pos - 1) * sizeof(wchar_t);
    memmove(dest, src, size);
    s_buffer = realloc(s_buffer, (len) * sizeof(wchar_t));
    s_buffer[len - 1] = 0;
}
