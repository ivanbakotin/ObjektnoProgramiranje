#include "main.hpp"

int main() {
    Point p1(2, 2), p2(5, 4), p3(8, 2),
    p4(8, 16);
    Board b(10, 20, '0');
    b.draw_line(p2, p1, 'x');
    b.draw_line(p3, p2, 'x');
    b.display();
}
