#include <glut.h>
#include <iostream>

float angle = 0.0; // Góc quay của khối cầu 1 quanh trục x

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Màu nền TRẮNG
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

    // Khối cầu 1
    glPushMatrix();
    glColor3f(1.0, 0.5, 0.0); // Màu cam
    glTranslatef(-2.0, 0.0, 0.0); // Di chuyển khối cầu 1 sang trái
    glRotatef(angle, 1.0, 0.0, 0.0); // Quay khối cầu 1 quanh trục x
    glutWireSphere(1.0, 50, 50); // Vẽ khối cầu 1 dưới dạng lưới
    glPopMatrix();

    // Khối cầu 2
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.922); // Màu xanh
    glTranslatef(.0, 0.0, 0.0); // Di chuyển khối cầu 2 sang phải
    glutWireSphere(1.0, 50, 50); // Vẽ khối cầu 2 dưới dạng lưới
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
        angle += 5.0; // Tăng góc quay của khối cầu 1 quanh trục x
        if (angle > 360.0) // Quay vòng lại nếu vượt quá 360 độ
            angle -= 360.0;
        glutPostRedisplay(); // Yêu cầu vẽ lại cảnh
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "An vao ban phim:" << std::endl;
    std::cout << "a: xoay quanh truc x" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH3 - 4");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
