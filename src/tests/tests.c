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
    "buffer_insert_5",
    "buffer_remove_1",
    "buffer_remove_2",
    "buffer_remove_3"
};
bool (*const TEST_FUNCS[])(void) = {
    test_buffer_insert_1,
    test_buffer_insert_2,
    test_buffer_insert_3,
    test_buffer_insert_4,
    test_buffer_insert_5,
    test_buffer_remove_1,
    test_buffer_remove_2,
    test_buffer_remove_3,
};

int main(void) {
    size_t i, total_tests, passed_tests = 0, failed_tests = 0;
    total_tests = sizeof(TEST_NAMES) / sizeof(TEST_NAMES[0]);

    printf("total tests: %lu\n", total_tests);

    for (i = 0; i < total_tests; i++) {
        printf("test %s... ", TEST_NAMES[i]);
        if (!TEST_FUNCS[i]()) {
            failed_tests++;
            printf("failed\n");
        } else {
            passed_tests++;
            printf("passed\n");
        }
    }

    printf("passed: %lu, failed: %lu\n", passed_tests, failed_tests);

    return failed_tests > 0 ? 1 : 0;
}
