#if !defined(RENDERER_H)
    #define RENDERER_H

typedef struct Renderer {
    int text_off_y, text_off_x;
} Renderer;

extern Renderer renderer;

extern void Renderer_RenderBuffer();

#endif // RENDERER_H
