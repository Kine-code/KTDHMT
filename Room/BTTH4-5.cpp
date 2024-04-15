
#include <glut.h>
#include <iostream>

static int day = 0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Thanh trượt màu đỏ
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); // Màu đỏ
    glRotatef(45, 0, 0, 1);
    glScalef(15, 0.6, 5);
    glutWireCube(1.0);
    glPopMatrix();

    // Quả bóng được chiếu sáng màu xanh lá cây
    glPushMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_pos[] = { 5.0, 7.0, 5.0, 1.0 }; // Vị trí ánh sáng
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    GLfloat light_diffuse[] = { 0.0, 1.0, 0.0, 1.0 }; // Màu ánh sáng (xanh lá cây)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glTranslatef(5, 7, 0);
    glTranslatef((GLfloat)day / 40, (GLfloat)day / 40, 0);
    glRotatef(((GLfloat)day) * (-1), 0, 0, 1);
    glutSolidSphere(1, 20, 15); // Sử dụng glutSolidSphere thay vì glutWireSphere để có hình dạng đầy đủ
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 20, 0.0, 0.0, 0.0, 0, 1, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '.':
        day = (day + 1) / 1.1;
        glutPostRedisplay();
        break;
    case ',':
        day = (day - 1) * 1.1;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "An vao ban phim:" << std::endl;
    std::cout << ".: lan" << std::endl;
    std::cout << ",: lui lai" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
