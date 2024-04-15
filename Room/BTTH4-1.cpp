#include <glut.h>

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
    GLfloat light_color[] = { 0.0, 1.0, 1.0, 1.0 }; // Màu ánh sáng (xanh da trời)

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

    glutSolidSphere(1.0, 50, 50); // Vẽ một khối cầu

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // Góc nhìn, tỉ lệ khung hình, độ sâu gần, độ sâu xa
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH4-1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
