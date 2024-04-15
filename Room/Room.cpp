#include <glut.h>
#include <math.h>

bool isLightOn = true;
float angleX = 0.0f; // xoay truc x
float angleY = 0.0f;// xoay truc y
float zoom = 8.45f;  // Khoảng cách từ camera đến vị trí quan sát

void drawTable() {
    // Mặt bàn
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(5.95, 1.65, 4.0);  // thay doi vi tri
    glScalef(1.5, 0.1, 1.0); // thay doi kich thuoc
    glutSolidCube(1.0); // khoi lap phuong
    glPopMatrix();

    // chân bàn
    
    for (float x = 5.50; x <=  6.50; x += 1.0) { // toa do truc x
        for (float z = 3.45; z <= 4.45; z += 1.0) { // toa do truc z
            glPushMatrix();
            glTranslatef(x, 1.35, z);// truc y
            glScalef(0.1, 0.5, 0.1);
            glutSolidCube(1.0);
            glPopMatrix();
        }
    }
}

void drawSofa() {
    // mặt sofa
    glColor3f(0.8, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(6.0, 1.5, 2.5);
    glScalef(2.0, 0.6, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // dựa sofa
    glColor3f(0.8, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(6.0, 1.7, 2.0);
    glScalef(2.0, 1.2, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    
}

void drawBed() {
    // than giuong
    glColor3f(0.62, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(2.45, 1.35, 2.0);
    glScalef(2.5, 0.5, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();
    // dau giuong
    glPushMatrix();
    glTranslatef(1.15, 1.35, 2.0);
    glScalef(0.25, 0.95, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();
    // chan
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(2.60, 1.40, 2.05);
    glScalef(2.0, 0.5, 1.25);
    glutSolidCube(1.0);
    glPopMatrix();
    
}
void drawCabinet() {
    // tu qao
    glColor3f(0.5, 0.25, 0.0);
    glPushMatrix();
    glTranslatef(1.45, 2.25, 5.25);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(1.95, 2.5, 0.8);
    glutSolidCube(1.0);
    glPopMatrix();
}
void drawWindow() {
    glColor3f(0.3, 0.6, 0.9);
    glPushMatrix();
    glTranslatef(2.55, 2.55, 1.0);
    glScalef(1.35, 1.35, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawClock() {
    // Vẽ mặt đồng hồ
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
    glTranslatef(5.65, 3.0, 2.0);
    glScalef(0.3, 0.3, 0.1);
    glutSolidTorus(0.2, 0.5, 20, 20);
    glPopMatrix();

    // Vẽ kim giờ
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(5.65, 3.0, 2.0);
    glRotatef(30 * 6.0, 0.0, 0.0, 1.0);
    glScalef(0.3, 0.03, 0.01);
    glutSolidCube(1.0);
    glPopMatrix();

    // Vẽ kim phút
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(5.65, 3.0, 2.0);
    glRotatef(6 * 10.0, 0.0, 0.0, 1.0);
    glScalef(0.3, 0.02, 0.008);
    glutSolidCube(1.0);
    glPopMatrix();

    // Vẽ kim giây
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(5.65, 3.0, 2.0);
    glRotatef(6 * 10.0, 0.0, 0.0, 1.0);
    glScalef(0.3, 0.01, 0.005);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawCarpet() {
    // thảm
    glColor3f(0.75, 0.75, 0.75);
    glPushMatrix();
    glTranslatef(3.05, 1.05, 2.75);  // thay doi vi tri
    glScalef(3.05, -0.05, 3.05); // thay doi kich thuoc
    glutSolidCube(1.0); // khoi lap phuong
    glPopMatrix();
}

void drawCeilingLight() {
    GLfloat light_position[] = { 4.0, 3.9, 4.0, 1.0 };
    GLfloat light_ambient[] = { 0.75, 0.75, 0.75 , 0.75 };
    GLfloat light_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };

    if (isLightOn) {
        glEnable(GL_LIGHTING);//bat che do chieu sang
        glEnable(GL_LIGHT0);// Bat nguon sang 0
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);// thiet lap vi tri nguon snag
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);// thiet lap mau phan xa xung quanh
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);// thiet lap phan xa tu nguon sang
    }
    else {
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
    }

    // Den 1
    glPushMatrix();
    glTranslatef(4.0, 3.9, 4.0);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Den 2 
    glPushMatrix();
    glTranslatef(2.5, 3.9, 5.5);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
}

void init(void) {
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };// mau sac tu phan xa tu be mat
    GLfloat mat_shininess[] = { 50.0 };// do pong

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_DEPTH_TEST);
    // thiet lap mau chieu
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(6.25, 3.25, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angleX, 0.0f, 1.0f, 0.0f);
    glRotatef(angleY, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -zoom);

    // Tran Nha
    glColor3f(0.4, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(1.0, 4.0, 1.0);
    glVertex3f(7.0, 4.0, 1.0);
    glVertex3f(7.0, 4.0, 7.0);
    glVertex3f(1.0, 4.0, 7.0);
    glEnd();

    // San Nha
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(7.0, 1.0, 1.0);
    glVertex3f(7.0, 1.0, 7.0);
    glVertex3f(1.0, 1.0, 7.0);
    glEnd();

    // Tuong
    glColor3f(0.4, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 4.0, 1.0);
    glVertex3f(1.0, 4.0, 7.0);
    glVertex3f(1.0, 1.0, 7.0);
    glEnd();

    // Tuong ben trai 
    glColor3f(0.5, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 4.0, 1.0);
    glVertex3f(7.0, 4.0, 1.0);
    glVertex3f(7.0, 1.0, 1.0);
    glEnd();

    // Tường phía sau
    glColor3f(0.4, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 1.0, 1.0);
    glVertex3f(7.0, 4.0, 1.0);
    glVertex3f(7.0, 4.0, 7.0);
    glVertex3f(7.0, 1.0, 7.0);
    glEnd();

   // bàn
    drawTable();
    //sofa
    drawSofa();
    // giường
    drawBed();
    // tủ qao
    drawCabinet();
    // cửa sổ
    drawWindow();
    //đồng hồ
    drawClock();
    // thảm
    drawCarpet();
    
    // Đèn trần
    drawCeilingLight();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(6.25, 3.25, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) { 
    switch (key) {
    case '1':
        isLightOn = true;
        glutPostRedisplay();
        break;
    case '2':
        isLightOn = false;
        glutPostRedisplay();
        break;
    case 'w':
        angleX -= 5.0f;
        break;
    case 's':
        angleX += 5.0f;
        break;
    case 'a':
        angleY -= 5.0f;
        break;
    case 'd':
        angleY += 5.0f;
        break;
    case '+':
        zoom -= 0.5f;
        break;
    case '-':
        zoom += 0.5f;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Phong cua Kien");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
