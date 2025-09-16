#ifndef CONFIG_H
#define CONFIG_H

#include "../vendors/raylib/build/raylib/include/raylib.h"

#define PROJECT_NAME "Aves"
#define PROJECT_VERSION "0.1.0"

typedef struct {
    int width;
    int height;
} Resolution;

extern const Resolution DEFAULT_RESOLUTION;

#endif // CONFIG_H