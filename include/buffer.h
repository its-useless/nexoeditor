#if !defined(BUFFER_H)
    #define BUFFER_H

    #include <stddef.h>

extern char* buffer;
extern size_t buffer_len;

extern void buffer_update();

#endif // BUFFER_H