#include "core/engine.h"
#include "taskmanager/taskmanager.h"

int main(void) {
    init_engine();
    loop_engine();
    close_engine();
    return EXIT_SUCCESS;
}