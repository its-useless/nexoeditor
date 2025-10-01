#include "tests/buffer.h"

#include <string.h>
#include <wchar.h>

#include "core/buffer.h"
#include "core/mem.h"
#include "core/state.h"

bool test_buffer_insert_1() {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(0, 'c');
    res = wcscmp(state.buffer, L"ctest") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_2() {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(4, 'c');
    res = wcscmp(state.buffer, L"testc") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_3() {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(1, 'c');
    res = wcscmp(state.buffer, L"tcest") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_4() {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(1, 'c');
    res = wcscmp(state.buffer, L"tccest") == 0;
    xfree(state.buffer);

    return res;
}

bool test_buffer_insert_5() {
    bool res;

    state.buffer = xstralloc(L"test");
    Buffer_InsertChar(1, 'c');
    Buffer_InsertChar(0, 'c');
    Buffer_InsertChar(6, 'c');
    res = wcscmp(state.buffer, L"ctcestc") == 0;
    xfree(state.buffer);

    return res;
}
