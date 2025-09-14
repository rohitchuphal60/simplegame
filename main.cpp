#include "raylib.h"
#include <GL/gl.h>  // OpenGL header

int main() {
    InitWindow(800, 600, "Raylib + OpenGL");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib!", 190, 200, 20, LIGHTGRAY);

        // Raw OpenGL example (draw a red line)
        glBegin(GL_LINES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0.5f, 0.5f);
        glEnd();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
