#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class timer {
    private:
        int h, m;
        double s;

        friend ostream& operator<<(ostream& os, const timer& dt);

    public:
        void addSeconds(int seconds);
        void addMinutes(int minutes);
        void addHour(int hour);

        void setSeconds(double seconds);
        void setMinutes(int minutes);
        void setHour(int hour);

        int getHour();
        int getMinutes();
        double getSeconds();

        timer();
        timer(int hour, int minute, double second);

        timer operator+= (timer const &obj);
        timer operator-= (timer const &obj);
        timer operator+ (timer const &obj);
        timer operator- (timer const &obj);
        timer operator/= (int divisor);
        timer operator/ (int divisor);
        bool operator< (timer const &obj);

        operator double ();
};

class penalty {
    private:
        double sec;

    public:
        penalty(double seconds) {
            sec = seconds;
        }

        penalty& operator() (timer &obj) { 
            obj.addSeconds(sec);

            if (obj.getSeconds() >= 60) {
                obj.addMinutes(1);
                obj.setSeconds(obj.getSeconds() -  60);
            }

            if (obj.getMinutes() >= 60) {
                obj.addHour(1);
                obj.setMinutes(obj.getMinutes() -  60);
            }
        }
};
