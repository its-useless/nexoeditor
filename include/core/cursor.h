#if !defined(CORE_CURSOR_H)
    #define CORE_CURSOR_H
    #include <stdbool.h>
    #include <stddef.h>
    #include <wchar.h>

typedef struct Cursor {
    int y, x;
} Cursor;

extern void Cursor_MoveUp(void);
extern void Cursor_MoveDown(void);
extern void Cursor_MoveLeft(void);
extern void Cursor_MoveRight(void);
extern bool Cursor_HandleKeypress(wchar_t key);
extern void Cursor_EnsurePosition(void);

#endif
