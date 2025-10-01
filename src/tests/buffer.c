#include "tests/buffer.h"

#include <string.h>

#include "core/buffer.h"
#include "core/mem.h"

bool test_buffer_insert_1() {
    bool res;

    buffer = xstralloc("test");
    Buffer_InsertChar(0, 'c');
    res = memcmp(buffer, "ctest\0", 6) == 0;
    xfree(buffer);

    return res;
}

bool test_buffer_insert_2() {
    bool res;

    buffer = xstralloc("test");
    Buffer_InsertChar(4, 'c');
    res = memcmp(buffer, "testc\0", 6) == 0;
    xfree(buffer);

    return res;
}

bool test_buffer_insert_3() {
    bool res;

    buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    res = memcmp(buffer, "tcest\0", 6) == 0;
    xfree(buffer);

    return res;
}

bool test_buffer_insert_4() {
    bool res;

    buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(1, 'c');
    res = memcmp(buffer, "tccest\0", 7) == 0;
    xfree(buffer);

    return res;
}

bool test_buffer_insert_5() {
    bool res;

    buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(0, 'c');
    Buffer_InsertChar(6, 'c');
    res = memcmp(buffer, "ctcestc\0", 8) == 0;
    xfree(buffer);

    return res;
}
