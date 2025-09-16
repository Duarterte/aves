#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include "../vendors/raylib/build/raylib/include/raylib.h"

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} DataType;

typedef struct {
    DataType type;
    union {
        int intValue;
        float floatValue;
        char *stringValue;
    } data;
} TaskData;

void safe_cleanup(void* _data);
void process_task_with_cleanup(TaskData* task);
#endif // TASKMANAGER_H