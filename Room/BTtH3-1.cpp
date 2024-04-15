#include <glut.h>
#include <iostream>

static float angle = 0.0;
static float teapotPosX = -2.0; // Vị trí ban đầu của ấm trà
static float teapotSpeed = 0.5; // Tốc độ di chuyển của ấm trà

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

    // Ấm trà 
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0); // đen
    glScalef(1.0, 1.0, 1.0); // thay doi kich thuoc
    glTranslatef(teapotPosX, 0.0, 0.0); // Di chuyển ấm trà sang trái
    glRotatef(angle, 1.0, 0.0, 0.0); // Quay ấm trà quanh trục x
    //glutSolidTeapot(1.0); // Vẽ ấm trà
    glutWireTeapot(1.0); // ÁM TRÀ DẠNG LƯỚI
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
        // Nếu ấm trà chưa chạm mép phải của cửa sổ
        if (teapotPosX + 1.0 < 3.5)
            teapotPosX += teapotSpeed; // Di chuyển ấm trà sang phải
    }
}

void timer(int value) {
    angle += 2.0; // Tăng góc quay
    if (angle > 360.0) // Quay vòng lại nếu vượt quá 360 độ
        angle -= 360.0;
    glutPostRedisplay(); // Yêu cầu vẽ lại cảnh
    glutTimerFunc(30, timer, 0); // Thiết lập hàm hẹn giờ cho lần tiếp theo
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    std::cout << "An chuot trai: dich phai" << std::endl;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH3 - 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse); // Đăng ký hàm xử lý sự kiện chuột
    glutTimerFunc(30, timer, 0); // Bắt đầu hàm hẹn giờ
    glutMainLoop();
    return 0;
}
