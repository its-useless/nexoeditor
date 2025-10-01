#include "tests/buffer.h"

#include <string.h>

#include "core/buffer.h"
#include "core/mem.h"
#include "core/state.h"

bool test_buffer_insert_1() {
    bool res;

    state.buffer = xstralloc("test");
    Buffer_InsertChar(0, 'c');
    res = memcmp(state.buffer, "ctest\0", 6) == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_2() {
    bool res;

    state.buffer = xstralloc("test");
    Buffer_InsertChar(4, 'c');
    res = memcmp(state.buffer, "testc\0", 6) == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_3() {
    bool res;

    state.buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    res = memcmp(state.buffer, "tcest\0", 6) == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_4() {
    bool res;

    state.buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(1, 'c');
    res = memcmp(state.buffer, "tccest\0", 7) == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_5() {
    bool res;

    state.buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(0, 'c');
    Buffer_InsertChar(6, 'c');
    res = memcmp(state.buffer, "ctcestc\0", 8) == 0;
    xfree(state.buffer);

    return res;
}
