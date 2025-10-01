#include <curses.h>
#include <stdio.h>
#include <string.h>

#include "core/buffer.h"
#include "core/mem.h"
#include "tests/buffer.h"

const char* TEST_NAMES[] = {
    "buffer_insert_1",
    "buffer_insert_2",
    "buffer_insert_3",
    "buffer_insert_4",
    "buffer_insert_5"
};
bool (*const TEST_FUNCS[])() = {
    test_buffer_insert_1,
    test_buffer_insert_2,
    test_buffer_insert_3,
    test_buffer_insert_4,
    test_buffer_insert_5
};

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