#include "raylib.h"

#define MAX_BLOCKS 20

typedef struct Block {
    Rectangle rect;
    float speed;
} Block;

int main(void) {
    InitWindow(800, 600, "Hello");
    SetTargetFPS(60);

    Rectangle player = { 400, 550, 50, 20 };
    int playerSpeed = 5;

    Block blocks[MAX_BLOCKS];
    for (int i = 0; i < MAX_BLOCKS; i++) {
        blocks[i].rect = (Rectangle){ GetRandomValue(0, 750), GetRandomValue(-600, 0), 50, 20 };
        blocks[i].speed = GetRandomValue(3, 6);
    }

    int score = 0;
    bool gameOver = false;

    while (!WindowShouldClose()) {
        // Update
        if (!gameOver) {
            if (IsKeyDown(KEY_LEFT) && player.x > 0) player.x -= playerSpeed;
            if (IsKeyDown(KEY_RIGHT) && player.x < 800 - player.width) player.x += playerSpeed;

            for (int i = 0; i < MAX_BLOCKS; i++) {
                blocks[i].rect.y += blocks[i].speed;

                if (blocks[i].rect.y > 600) {
                    blocks[i].rect.y = GetRandomValue(-200, -20);
                    blocks[i].rect.x = GetRandomValue(0, 750);
                    blocks[i].speed = GetRandomValue(2, 5);
                    score++; // survived this block
                }

                if (CheckCollisionRecs(player, blocks[i].rect)) {
                    gameOver = true;
                }
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Dodge the Falling Blocks!", 10, 10, 20, DARKPURPLE);
        DrawText(TextFormat("Score: %d", score), 10, 40, 20, DARKBLUE);
			         if (IsKeyPressed(KEY_B)){
				
                    CloseWindow();
                		}	
        if (gameOver) {
            DrawText("GAME OVER", 300, 250, 40, RED);
            DrawText("Press R to restart", 300, 300, 20, DARKGRAY);

            if (IsKeyPressed(KEY_R)) {
                // Reset game
                player.x = 400;
                score = 0;
                gameOver = false;
                for (int i = 0; i < MAX_BLOCKS; i++) {
                    blocks[i].rect.y = GetRandomValue(-600, 0);
                    blocks[i].rect.x = GetRandomValue(0, 750);
                }
            }
        }

        // Draw player
        DrawRectangleRec(player, BLUE);

        // Draw blocks
        for (int i = 0; i < MAX_BLOCKS; i++) {
            DrawRectangleRec(blocks[i].rect, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
