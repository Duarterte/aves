#include <stdio.h>
#include <stdlib.h>
#include "vendors/raylib/build/raylib/include/raylib.h"

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

void safe_cleanup(void* _data) {
    TaskData* data = (TaskData*)_data;
    if (!data) return;
    switch (data->type)
    {
    case TYPE_STRING:

        free(data->data.stringValue);
        data->data.stringValue = NULL;
        break;
    case TYPE_INT:
        data->data.intValue = 0;
        break;
    case TYPE_FLOAT:
        data->data.floatValue = 0.0f;
        break;
    default:
        break;
    }
}

void process_task_with_cleanup(TaskData* task) {
    if (!task) return;

    // Simulate task processing
    printf("Processing task of type %d\n", task->type);

    // After processing, clean up resources
    safe_cleanup(task);
}
void print_string_task(TaskData* task) {
    if (task && task->type == TYPE_STRING && task->data.stringValue) {
        printf("String Task: %s\n", task->data.stringValue);
    } else {
        printf("Invalid String Task\n");
    }
}

int main(void) {
    // Example usage
    TaskData stringTask;
    stringTask.type = TYPE_STRING;
    stringTask.data.stringValue = malloc(50 * sizeof(char));
    snprintf(stringTask.data.stringValue, 50, "Hello, World!");

    print_string_task(&stringTask);
    process_task_with_cleanup(&stringTask);

    // Verify cleanup
    print_string_task(&stringTask); // Should indicate invalid task
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}