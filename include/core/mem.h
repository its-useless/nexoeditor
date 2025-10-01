#if !defined(MEM_H)
    #define MEM_H

    #include <stddef.h>

extern void* xmalloc(size_t size);
extern char* xstralloc(const char* text);

extern void xfree(void* ptr);

#endif // MEM_H
