#if !defined(BUFFER_H)
    #define BUFFER_H

    #include <stddef.h>

extern char* buffer;

extern void Buffer_InsertChar(size_t pos, char c);

#endif // BUFFER_H