#include <GL/freeglut.h>
#include <string>
#include <iostream>

using namespace std ;
void renderBitmapString(float x, float y, void *font, const std::string &str) {
    glRasterPos2f(x, y);
    for (char c : str) {
        glutBitmapCharacter(font, c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Set text color (white)
    glColor3f(1.0, 1.0, 1.0);

    // Coordinates in normalized OpenGL coordinates (-1 to 1)
    // 0.0f on both axes is roughly center
    renderBitmapString(-0.05f, 0.0f, GLUT_BITMAP_HELVETICA_18, "rohit");

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Show Rohit");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 1.0);  // black background

    glutMainLoop();
    return 0;
}
