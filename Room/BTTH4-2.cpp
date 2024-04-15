﻿#include <glut.h>
#include <iostream>

static float angle = 0.0;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Màu nền trắng
    glEnable(GL_DEPTH_TEST); // Bật kiểm tra độ sâu
    glEnable(GL_LIGHTING); // Bật ánh sáng
    glEnable(GL_LIGHT0); // Bật ánh sáng số 0
    glEnable(GL_COLOR_MATERIAL); // Bật sử dụng màu vật liệu
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, // Vị trí máy ảnh
        0.0, 0.0, 0.0, // Điểm nhìn
        0.0, 1.0, 0.0); // Hướng lên trên

    GLfloat light_position[] = { 2.0, 2.0, 2.0, 1.0 }; // Vị trí ánh sáng
    GLfloat light_color[] = { 1.0, 1.0, 0.0, 1.0 }; // Màu ánh sáng (vàng)

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    // Ấm trà màu vàng
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0); // Màu vàng
    glTranslatef(1.75, 0.0, 0.0); // Di chuyển ấm trà sang phải
    glRotatef(angle, 0.0, 1.0, 0.0); // Quay ấm trà
    glutSolidTeapot(1.0); // Vẽ ấm trà
    glPopMatrix();

    // Ấm trà màu tía
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0); // Màu tía
    glTranslatef(-2.0, 0.0, 0.0); // Di chuyển ấm trà sang trái
    glutSolidTeapot(1.0); // Vẽ ấm trà
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // Góc nhìn, tỉ lệ khung hình, độ sâu gần, độ sâu xa
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        angle += 5.0; // Tăng góc quay
        if (angle > 360.0) // Quay vòng lại nếu vượt quá 360 độ
            angle -= 360.0;
        glutPostRedisplay(); // Yêu cầu vẽ lại cảnh
        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "An vao ban phim:" << std::endl;
    std::cout << "a: xoay quanh chinh no" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH4-2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
