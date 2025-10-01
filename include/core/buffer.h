#if !defined(CORE_BUFFER_H)
    #define CORE_BUFFER_H

    #include <stddef.h>

extern char* buffer;

extern void Buffer_InsertChar(size_t pos, char c);

#endif