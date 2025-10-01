#if !defined(CORE_MEM_H)
    #define CORE_MEM_H

    #include <stddef.h>
    #include <wchar.h>

extern void* xmalloc(size_t size);
extern wchar_t* xstralloc(const wchar_t* text);

extern void xfree(void* ptr);

#endif
