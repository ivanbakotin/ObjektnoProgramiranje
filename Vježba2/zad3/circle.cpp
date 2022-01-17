#include <iostream>

using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

struct Circle {
    int s1, s2, r;
};

int rectanglesOverlapCircle(const Rectangle rectangle[3], const Circle circle, int n) {

        int counter = 0;
    
        for(int i = 0; i < n; i++) {
            
            int closestX = (circle.s1 < rectangle[i].x1 ? rectangle[i].x1 : (circle.s1 > rectangle[i].x2 ? rectangle[i].x2 : circle.s1));
            int closestY = (circle.s2 < rectangle[i].y2 ? rectangle[i].y2 : (circle.s2 > rectangle[i].y1 ? rectangle[i].y1 : circle.s2));
            int dx = closestX - circle.s1;
            int dy = closestY - circle.s2;

            if (( dx * dx + dy * dy ) <= circle.r * circle.r) counter++;
        };

        return counter;
    };

int main() {

    struct Circle circle;
    struct Rectangle rectangle[3];

    circle.s1 = 1;
    circle.s2 = 1;
    circle.r = 1;

    rectangle[0] = { 1, 1, 1, 2 };
    rectangle[1] = { 1, 1, 1, 1 };
    rectangle[2] = { -36, -26, 46, 56 };

    int num = rectanglesOverlapCircle(rectangle, circle, 3);

    cout << "Number of rectangles overlapping the circle is: " << num << endl;
};
