#include "mem.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

void* xmalloc(size_t size) {
    void* ptr = malloc(size);
    assert(ptr);
    return ptr;
}

char* xstralloc(const char* text) {
    size_t len = strlen(text) + 1;
    char* ptr = xmalloc(len);
    memcpy(ptr, text, len);
    return ptr;
}

void xfree(void* ptr) {
    assert(ptr);
    free(ptr);
}