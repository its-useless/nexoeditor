#include <curses.h>
#include <stdio.h>
#include <string.h>

#include "core/buffer.h"
#include "core/mem.h"

bool test_buffer_insert_1() {
    buffer = xstralloc("test");
    Buffer_InsertChar(0, 'c');
    bool res = memcmp(buffer, "ctest\0", 6) == 0;
    xfree(buffer);

    return res;
}

bool test_buffer_insert_2() {
    buffer = xstralloc("test");
    Buffer_InsertChar(4, 'c');
    bool res = memcmp(buffer, "testc\0", 6) == 0;
    xfree(buffer);

    return res;
}

bool test_buffer_insert_3() {
    buffer = xstralloc("test");
    Buffer_InsertChar(1, 'c');
    bool res = memcmp(buffer, "tcest\0", 6) == 0;
    xfree(buffer);

    return res;
}

const char* TEST_NAMES[] =
    {"buffer_insert_1", "buffer_insert_2", "buffer_insert_3"};
bool (*const TEST_FUNCS[])() =
    {test_buffer_insert_1, test_buffer_insert_2, test_buffer_insert_3};

int main() {
    size_t i, total_tests;
    total_tests = sizeof(TEST_NAMES) / sizeof(TEST_NAMES[0]);
    printf("total tests: %lu\n", total_tests);
    for (i = 0; i < total_tests; i++) {
        printf("test %s... ", TEST_NAMES[i]);
        if (!TEST_FUNCS[i]()) {
            printf("failed\n");
        } else {
            printf("passed\n");
        }
    }
    return 0;
}