#include <glut.h>
#include <iostream>

static float angle = 0.0; // Góc quay của khối lập phương
static float translateX = 0.0; // Dịch chuyển theo trục x

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

    // Khối lập phương màu vàng
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0); // Màu vàng
    glRotatef(angle, 0.0, 1.0, 0.0); // Quay khối lập phương
    glTranslatef(translateX, 0.0, 0.0); // Tịnh tiến khối lập phương
    glutSolidCube(1.0); // Vẽ khối lập phương
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); // Góc nhìn, tỉ lệ khung hình, độ sâu gần, độ sâu xa
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        angle += 5.0; // Tăng góc quay
        translateX -= 0.1; // Tịnh tiến sang trái
        glutPostRedisplay(); // Yêu cầu vẽ lại cảnh
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "Dung chuot:" << std::endl;
    std::cout << "mouse: vua lan vua tinh tien sang trai" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH4-4");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
