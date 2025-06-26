#include <GL/glut.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>       
#include <algorithm>   
#include <iostream>


using namespace std ;
int windowWidth = 500;
int windowHeight = 500;

float playerX = 0.0f;
float playerSize = 0.1f;

struct Block {
    float x, y;
};

std::vector<Block> blocks;
float blockSize = 0.1f;
float blockSpeed = 0.01f;

bool gameOver = false;

void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (gameOver) {
        // Draw Game Over screen
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2f(-0.3f, 0.0f);
        const char *msg = "Game Over";
        while (*msg) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *msg++);
        }
        glutSwapBuffers();
        return;
    }

    // Draw player
    glColor3f(0.0, 1.0, 0.0);
    drawSquare(playerX, -0.9f, playerSize);

    // Draw blocks
    glColor3f(1.0, 0.0, 0.0);
    for (const auto &b : blocks) {
        drawSquare(b.x, b.y, blockSize);
    }

    glutSwapBuffers();
}

void timer(int value) {
    if (!gameOver) {
        // Move blocks
        for (auto &b : blocks) {
            b.y -= blockSpeed;

            // Collision detection
            if (b.y - blockSize < -0.9f + playerSize &&
                b.y + blockSize > -0.9f - playerSize &&
                fabs(b.x - playerX) < playerSize + blockSize) {
                gameOver = true;
            }
        }

        // Remove off-screen blocks
        blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [](Block &b) {
            return b.y < -1.2f;
        }), blocks.end());

        // Spawn new block randomly
        if (rand() % 30 == 0) {
            float x = (rand() % 200 - 100) / 100.0f; // Random between -1.0 and 1.0
            blocks.push_back({x, 1.0f});
        }

        glutPostRedisplay();
        glutTimerFunc(16, timer, 0); // ~60 FPS
    }
}

void keyboard(unsigned char key, int, int) {
    if (key == '4') {
        playerX -= 0.1f;
        if (playerX < -1.0f + playerSize)
            playerX = -1.0f + playerSize;
    } else if (key == '6') {
        playerX += 0.1f;
        if (playerX > 1.0f - playerSize)
            playerX = 1.0f - playerSize;
    } else if (key == 'r' && gameOver) {
        // Restart game
        gameOver = false;
        blocks.clear();
        playerX = 0.0f;
        glutTimerFunc(16, timer, 0);
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    srand(time(0));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Dodge Game");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
