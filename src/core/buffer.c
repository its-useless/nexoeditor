#include "core/buffer.h"

#include <stdlib.h>
#include <string.h>

char* buffer = NULL;

void Buffer_InsertChar(size_t pos, char c) {
    char* p = buffer;
    size_t len = 0;

    while (*p) {
        p++;
        len++;
    }

    buffer = realloc(
        buffer,
        len + 1 + 1
    ); // one for the new char one for the null byte (isn't included in len)
    memmove(buffer + pos + 1, buffer + pos, len + 1 - pos);
    buffer[pos] = c;
}