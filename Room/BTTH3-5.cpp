#include <glut.h>
#include <iostream>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 3.55, 6.25, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Vẽ hình hộp chữ nhật màu xanh
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(1.0, 1.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Vẽ hình hộp chữ nhật thứ hai (màu xanh)
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0); 
    glScalef(1.0, 1.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Two Rectangular Prisms");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
