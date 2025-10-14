#include "tests/buffer.h"

#include <string.h>
#include <wchar.h>

#include "core/buffer.h"
#include "core/mem.h"
#include "core/state.h"

/* insert */
bool test_buffer_insert_1(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(0, 'c');
    res = wcscmp(state.buffer, L"ctest") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_2(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(4, 'c');
    res = wcscmp(state.buffer, L"testc") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_3(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(1, 'c');
    res = wcscmp(state.buffer, L"tcest") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_4(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(1, 'c');
    res = wcscmp(state.buffer, L"tccest") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_5(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(0, 'c');
    Buffer_InsertChar(6, 'c');
    res = wcscmp(state.buffer, L"ctcestc") == 0;
    xfree(state.buffer);

    return res;
}

/* remove */
bool test_buffer_remove_1(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_RemoveChar(0);
    res = wcscmp(state.buffer, L"est") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_remove_2(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_RemoveChar(1);
    res = wcscmp(state.buffer, L"tst") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_remove_3(void) {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_RemoveChar(4);
    res = wcscmp(state.buffer, L"tes") == 0;
    xfree(state.buffer);

    return res;
}

