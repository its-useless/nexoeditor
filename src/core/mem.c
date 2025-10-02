#include "core/mem.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

void* xmalloc(size_t size) {
    void* ptr = malloc(size);
    assert(ptr);
    return ptr;
}

void* xmalloc_chunk(size_t size, size_t chunk_size) {
    return xmalloc(size * chunk_size);
}

wchar_t* xstralloc(const wchar_t* text) {
    size_t len = wcslen(text) * sizeof(wchar_t) + sizeof(wchar_t);
    wchar_t* ptr = xmalloc(len);
    memcpy(ptr, text, len);
    return ptr;
}

void xfree(void* ptr) {
    assert(ptr);
    free(ptr);
}
