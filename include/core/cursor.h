#if !defined(CURSOR_H)
    #define CURSOR_H
    #include <stdbool.h>
    #include <stddef.h>

typedef struct Cursor {
    int y, x;
} Cursor;

extern Cursor cursor;

extern void Cursor_MoveUp();
extern void Cursor_MoveDown();
extern void Cursor_MoveLeft();
extern void Cursor_MoveRight();
extern bool Cursor_HandleKeypress(int key);
extern void Cursor_EnsurePosition();

#endif // CURSOR_H
