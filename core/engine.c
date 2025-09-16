 #include "engine.h"
 
 void init_engine() {
    InitWindow(DEFAULT_RESOLUTION.width, DEFAULT_RESOLUTION.height, PROJECT_NAME " - " PROJECT_VERSION);
}

void loop_engine() {    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
}

void close_engine() {
    CloseWindow();
}