#include <glut.h>
#include <cmath>
#include <iostream>

#define PI 3.14159265

// Biến lưu trạng thái của ngôi sao
float starRotation = 0.0f; // Góc quay của ngôi sao quanh tâm của nó
float starVertexRotation = 0.0f; // Góc quay của ngôi sao quanh một đỉnh cánh của nó
float starScale = 1.0f; // Tỉ lệ thu nhỏ của ngôi sao
bool shrinking = false; // Biến xác định ngôi sao đang thu nhỏ hay không
int lastMouseX = 0; // Tọa độ x của chuột khi cuối cùng được nhấn
bool mousePressed = false; // Biến xác định trạng thái nhấn chuột

// Hàm vẽ một đoạn đường thẳng từ (x1, y1) đến (x2, y2)
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Hàm vẽ một ngôi sao 5 cánh
void drawStar(float centerX, float centerY, float size) {
    float outerRadius = size;
    float innerRadius = size / 2.5;

    // Tính toán các góc của các đỉnh của ngôi sao
    float angleIncrement = 72.0f;
    float angle = starVertexRotation - 90.0f; // Bắt đầu từ đỉnh của ngôi sao
    float x, y, xInner, yInner;

    // Vẽ ngôi sao
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 5; ++i) {
        x = centerX + outerRadius * cos(angle * PI / 180.0f);
        y = centerY + outerRadius * sin(angle * PI / 180.0f);
        glVertex2f(x, y);

        xInner = centerX + innerRadius * cos((angle + angleIncrement / 2.0f) * PI / 180.0f);
        yInner = centerY + innerRadius * sin((angle + angleIncrement / 2.0f) * PI / 180.0f);
        glVertex2f(xInner, yInner);

        angle += angleIncrement;
    }
    glEnd();
}

// Hàm vẽ
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Vẽ ngôi sao
    glColor3f(1.0f, 1.0f, 0.0f); // Màu vàng
    drawStar(0.0f, 0.0f, 0.5f * starScale); // Vẽ ngôi sao với kích thước được điều chỉnh bởi starScale

    // Vẽ hình tròn bao quanh ngôi sao
    glColor3f(1.0f, 0.0f, 0.0f); // Màu đỏ
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 5) {
        float radian = i * PI / 180.0f;
        glVertex2f(0.5f * cos(radian), 0.5f * sin(radian));
    }
    glEnd();

    glutSwapBuffers();
}

// Hàm xử lý sự kiện nhấn phím
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        // Khi nhấn phím 'a', ngôi sao quay quanh một đỉnh cánh của nó
        starVertexRotation += 5.0f;
        if (starVertexRotation >= 360.0f)
            starVertexRotation -= 360.0f;
        glutPostRedisplay();
        break;
    case 'b':
        // Khi nhấn phím 'b', ngôi sao bắt đầu thu nhỏ
        shrinking = true;
        break;
    default:
        break;
    }
}

// Hàm xử lý sự kiện nhấn chuột
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            // Khi nhấn chuột trái, lưu tọa độ x của chuột
            lastMouseX = x;
            mousePressed = true;
        }
        else if (state == GLUT_UP) {
            // Khi nhả chuột trái, đặt trạng thái nhấn chuột về false
            mousePressed = false;
        }
    }
}

// Hàm cập nhật trạng thái của ngôi sao
void update(int value) {
    // Kiểm tra nếu chuột được nhấn và di chuyển, cập nhật góc quay của ngôi sao dựa trên sự thay đổi của tọa độ x của chuột
    if (mousePressed) {
        int dx = glutGet(GLUT_WINDOW_WIDTH) / 2 - lastMouseX; // Tính toán sự thay đổi tọa độ x của chuột
        starRotation += dx * 0.1f; // Sử dụng sự thay đổi tọa độ x để cập nhật góc quay của ngôi sao
        lastMouseX = glutGet(GLUT_WINDOW_WIDTH) / 2; // Cập nhật lại tọa độ x của chuột để chuột giữ vị trí ở giữa cửa sổ
        glutPostRedisplay();
    }

    // Kiểm tra nếu ngôi sao đang thu nhỏ
    if (shrinking) {
        starScale -= 0.05f; // Giảm kích thước của ngôi sao
        if (starScale <= 0.5f) // Nếu kích thước giảm xuống còn một nửa, dừng lại
            shrinking = false;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

// Hàm thiết lập các thuộc tính ban đầu cho cửa sổ
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Màu nền trắng
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Thiết lập hệ tọa độ
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Hàm chính
int main(int argc, char** argv) {
    glutInit(&argc, argv);

    std::cout << "nhan trai chuot ngoi sao quay quanh tam cua no:" << std::endl;
    std::cout << "a: ngoi sao quay quanh mot đinh canh cua no" << std::endl;
    std::cout << "b: mot lan, ngoi sao tu tu thu nho kich thuoc" << std::endl;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BTTH3-2");

    init(); // Khởi tạo cửa sổ

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Đăng ký hàm xử lý sự kiện nhấn phím
    glutMouseFunc(mouse); // Đăng ký hàm xử lý sự kiện chuột
    glutTimerFunc(25, update, 0); // Bắt đầu cập nhật trạng thái của ngôi sao

    glutMainLoop();
    return 0;
}
