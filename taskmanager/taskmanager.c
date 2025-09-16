#include "taskmanager.h"

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
    safe_cleanup(task);
}