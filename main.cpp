// Board dimensions
#include "raylib.h"
#include <GL/gl.h>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>   // <-- add this for rand/srand
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int BLOCK_SIZE = 30;

// Tetromino shapes (4x4 grid)
const std::vector<std::array<std::array<int, 4>, 4>> tetrominoes = {
    // I
    {{{0,0,0,0},
      {1,1,1,1},
      {0,0,0,0},
      {0,0,0,0}}},
    // O
    {{{0,0,0,0},
      {0,1,1,0},
      {0,1,1,0},
      {0,0,0,0}}},
    // T
    {{{0,0,0,0},
      {1,1,1,0},
      {0,1,0,0},
      {0,0,0,0}}},
    // L
    {{{0,0,0,0},
      {1,1,1,0},
      {1,0,0,0},
      {0,0,0,0}}},
    // J
    {{{0,0,0,0},
      {1,1,1,0},
      {0,0,1,0},
      {0,0,0,0}}},
    // S
    {{{0,0,0,0},
      {0,1,1,0},
      {1,1,0,0},
      {0,0,0,0}}},
    // Z
    {{{0,0,0,0},
      {1,1,0,0},
      {0,1,1,0},
      {0,0,0,0}}}
};

struct Tetromino {
    std::array<std::array<int, 4>, 4> shape;
    int x, y;
};

// Game board
int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};

// Check collision
bool CheckCollision(const Tetromino &piece, int nx, int ny) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece.shape[i][j]) {
                int x = nx + j;
                int y = ny + i;
                if (x < 0 || x >= BOARD_WIDTH || y >= BOARD_HEIGHT) return true;
                if (y >= 0 && board[y][x]) return true;
            }
        }
    }
    return false;
}

// Lock piece into the board
void PlacePiece(const Tetromino &piece) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece.shape[i][j]) {
                board[piece.y + i][piece.x + j] = 1;
            }
        }
    }
}

// Clear full lines
void ClearLines() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        bool full = true;
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (!board[i][j]) { full = false; break; }
        }
        if (full) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    board[k][j] = board[k-1][j];
                }
            }
            for (int j = 0; j < BOARD_WIDTH; j++) board[0][j] = 0;
        }
    }
}

// Rotate tetromino
Tetromino Rotate(const Tetromino &piece) {
    Tetromino rotated = piece;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rotated.shape[j][3 - i] = piece.shape[i][j];
        }
    }
    return rotated;
}

int main() {
    InitWindow(BOARD_WIDTH * BLOCK_SIZE, BOARD_HEIGHT * BLOCK_SIZE, "Tetris - Raylib + OpenGL");
    SetTargetFPS(60);
    srand(time(0));

    Tetromino current { tetrominoes[rand() % tetrominoes.size()], BOARD_WIDTH/2 - 2, 0 };
    float timer = 0.0f;
    float delay = 0.5f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        timer += dt;

        // Controls
        if (IsKeyPressed(KEY_LEFT) && !CheckCollision(current, current.x - 1, current.y)) current.x--;
        if (IsKeyPressed(KEY_RIGHT) && !CheckCollision(current, current.x + 1, current.y)) current.x++;
        if (IsKeyPressed(KEY_DOWN) && !CheckCollision(current, current.x, current.y + 1)) current.y++;
        if (IsKeyPressed(KEY_UP)) {
            Tetromino r = Rotate(current);
            if (!CheckCollision(r, current.x, current.y)) current = r;
        }

        // Auto move down
        if (timer > delay) {
            if (!CheckCollision(current, current.x, current.y + 1)) {
                current.y++;
            } else {
                PlacePiece(current);
                ClearLines();
                current = Tetromino { tetrominoes[rand() % tetrominoes.size()], BOARD_WIDTH/2 - 2, 0 };
                if (CheckCollision(current, current.x, current.y)) {
                    // Game over
                    for (int i = 0; i < BOARD_HEIGHT; i++)
                        for (int j = 0; j < BOARD_WIDTH; j++)
                            board[i][j] = 0;
                }
            }
            timer = 0;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (board[i][j]) {
                    DrawRectangle(j*BLOCK_SIZE, i*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, BLUE);
                }
            }
        }

        // Draw current piece
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (current.shape[i][j]) {
                    DrawRectangle((current.x+j)*BLOCK_SIZE, (current.y+i)*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, RED);
                }
            }
        }

        // Example OpenGL overlay (draws a simple line at top)
        glBegin(GL_LINES);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(-1.0f, 0.9f);
            glVertex2f(1.0f, 0.9f);
        glEnd();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
