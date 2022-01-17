#include "main.hpp"
#include <iostream>

using namespace std;

Point::Point (double i, double j) {
    x = i;
    y = j;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

int Board::doubleXToInt(Point &p) {
    double x = p.getX();
    x = x + 0.5 - (x < 0);
    return (int)x; 
}

int Board::doubleYToInt(Point &p) {
    double y = p.getY();
    y = y + 0.5 - (y < 0);
    return (int)y; 
}

void Board::constructorHelper(char border) {
    data = new char*[rows];

    for(int i = 0; i < rows; i++) {
        data[i] = new char[cols];
    };

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || j == cols - 1 || i == rows - 1) {
                data[i][j] = border;
            } else {
                data[i][j] = ' ';
            }
        };
    };
}

Board::Board() {
    rows = 10;
    cols = 10;
    char border = '0';

    constructorHelper(border);
};

Board::Board (int x, int y, char c) {
    rows = x; 
    cols = y; 
    char border = c;

    constructorHelper(border);
}

Board::Board (const Board &obj) {
    data = new char*[obj.rows];
    
    for(int i = 0; i < rows; i++) {
        data[i] = new char[obj.cols];
    };
}  

Board::Board (Board &&obj) {
    data = new char*[obj.rows];
    
    for(int i = 0; i < rows; i++) {
        data[i] = new char[obj.cols];
    };

    for(int i = 0; i < rows; i++) {
        delete obj.data[i];
    };

    delete obj.data;
}

Board::~Board() {
    for(int i = 0; i < rows; i++) {
        delete data[i];
    };

    delete data;
};

void Board::draw_char(Point p, char ch) {

    int x = doubleXToInt(p);
    int y = doubleYToInt(p);

    data[x][y] = ch;
}

void Board::draw_up_line(Point p, char ch) {

    int x = doubleXToInt(p);
    int y = doubleYToInt(p);

    for (int i = x; i > 0; i--) {
        data[i][y] = ch;
    }
} 

void Board::draw_line(Point p1, Point p2, char ch) {

    int x1 = doubleXToInt(p1);
    int x2 = doubleXToInt(p2);

    int y1 = doubleYToInt(p1);
    int y2 = doubleYToInt(p2);

    int i = x1, j = y1;

    data[x2][y2] = ch;

    while (x1 != x2 || y1 != y2) {

        data[i][j] = ch;

        if (x1 > x2) {

            i = ++x2;

            if (y1 > y2) j = ++y2;
            else if (y2 > y1) j = --y2;

        } else if (x2 > x1){

            i = ++x1;

            if (y1 > y2) j = --y1;
            else if (y2 > y1) j = ++y1;

        } else {
            if (y1 > y2) j = --y1;
            else if (y2 > y1) j = ++y1;
        }
    }
}

void Board::display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << data[i][j];
        };
        cout<<endl;
    };
}
