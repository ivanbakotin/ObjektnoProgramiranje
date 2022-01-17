#include <iostream>
#include <time.h>
#include <iomanip>
#include <tgmath.h>
#include <cstdlib>

using namespace std;

class Dot {
    double x = 0, y = 0, z = 0;

    public:

        void generateDot() {
            double L1, L2;

            cout << "First interval number: " << endl;
            cin >> L1;
            cout << "Last interval number: " << endl;
            cin >> L2;

            srand ( time(NULL) );

            x = L1 + (rand()) /((RAND_MAX/(L2-L1)));
            y = L1 + (rand()) /((RAND_MAX/(L2-L1)));
            z = L1 + (rand()) /((RAND_MAX/(L2-L1)));
        }

        double getX() {
            return x;
        }

        double getY() {
            return y;
        }

        double getZ() {
            return z;
        }

        double distance2D(double x2, double y2) {
            return sqrt(pow(x2 - x, 2) +
                        pow(y2 - y, 2) * 1.0);
        }

        double distance3D(double x2, double y2, double z2) {
            return sqrt(pow((x - x2), 2) +
                        pow((y - y2), 2) +
                        pow((z - z2), 2));
        }
};

class Gun {
    public:

        Dot dot;
        int magazine = 3, ammo = 100;

        void shoot() {
            magazine--;
        }

        void reload() {
            ammo -= 3 - magazine;
            magazine = 3;
        }
};

class Target {
    public:

        Dot dotx;
        Dot doty;
        bool hit;
};

int main() {
    Dot dot_1;
    Dot dot_2;

    //dot_1.generateDot();
    //dot_2.generateDot();

    //double x = dot_2.getX();
    //double y = dot_2.getY();
    //double z = dot_2.getZ();

    //cout << dot_1.distance2D(x, y) << endl;
    //cout << dot_1.distance3D(x, y, z) << endl;

    Gun gun;

    gun.dot.generateDot();

    Target target[10];

    for (int i = 0; i < 2; i++) {
        target[i].dotx.generateDot();
        target[i].doty.generateDot();
    }

    for (int i = 0; i < 2; i++) {
        gun.shoot();
        if (gun.magazine) {
            if (min(target[i].dotx.getY(), target[i].doty.getY())<=gun.dot.getY()<=max(target[i].dotx.getY(), target[i].doty.getY()))                 
            {
                target[i].hit = true;
                cout << "HIT" << endl;
            } else {
                target[i].hit = false;
                cout << "MISS" << endl;
            }
        } else {
            cout << "Out of bullets in magazine" << endl;
        }
    }
}
