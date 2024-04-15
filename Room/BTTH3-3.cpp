#include <glut.h>
#include <iostream>

static float angle = 0.0;
static bool rotateSphere = false;

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
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, -0.75, 0.0);
    glRotatef(3.5, 1.0, 0.0, 0.0);
    glutWireCube(1.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0); // Thêm xoay khối cầu
    glutWireSphere(1.0, 50, 50);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        rotateSphere = !rotateSphere; // Đảo trạng thái quay của khối cầu
    }
}

void update(int value) {
    if (rotateSphere) {
        angle += 1.0; // Tăng góc quay
        if (angle > 360.0)
            angle -= 360.0;
    }
    glutPostRedisplay();
    glutTimerFunc(10, update, 0); // Gọi lại hàm update sau mỗi 10ms
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "An vao ban phim:" << std::endl;
    std::cout << "Click trai chuot: xoay quanh khối cầu" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH3-3");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutTimerFunc(10, update, 0); // Khởi tạo bộ đếm thời gian
    glutMainLoop();
    return 0;
}
