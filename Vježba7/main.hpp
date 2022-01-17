class Point {
    private:
        double x, y;

    public:
        Point (double i, double j);
        double getX();
        double getY();
};

class Board {
    private:
        int rows, cols;
        char **data;

        int doubleXToInt(Point &p);
        int doubleYToInt(Point &p);
        void constructorHelper(char border);

    public:
        Board();
        Board (int x, int y, char c);
        Board (const Board &obj);
        Board (Board &&obj);
        ~Board();
        void draw_char(Point p, char ch);
        void draw_up_line(Point p, char ch);
        void draw_line(Point p1, Point p2, char ch);
        void display();
};