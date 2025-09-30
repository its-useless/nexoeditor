#include "buffer.h"

#include <stdlib.h>
#include <string.h>

char* buffer = NULL;
size_t buffer_len = 0;

void buffer_update() {
    buffer_len = strlen(buffer);
}