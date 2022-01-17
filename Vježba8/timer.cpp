#include "timer.hpp"

void timer::addSeconds(int seconds) {
    s += seconds;

    if (s >= 60) {
        m++;
        s -= 60;
    }

    if (m >= 60) {
        h++;
        m -= 60;
    }
}

void timer::addMinutes(int minutes) {
    m += minutes;

    if (m >= 60) {
        h++;
        m -= 60;
    }
}

void timer::addHour(int hour) {
    h += hour;
}

void timer::setSeconds(double seconds) {
    s = seconds;
}

void timer::setMinutes(int minutes) {
    m = minutes;
}

void timer::setHour(int hour) {
    h = hour;
}

int timer::getHour() {
    return h;
}

int timer::getMinutes() {
    return m;
}

double timer::getSeconds() {
    return s;
}

timer::timer() {
    h = 0;
    m = 0;
    s = 0;
}

timer::timer(int hour, int minute, double second) {
    h = hour;
    m = minute;
    s = second;
}

timer timer::operator+= (timer const &obj) {

    h += obj.h;
    m += obj.m;
    s += obj.s;

    if (s >= 60) {
        m++;
        s -= 60;
    }

    if (m >= 60) {
        h++;
        m -= 60;
    }
            
    return *this;
}

timer timer::operator+ (timer const &obj) {

    timer result;

    result.h = h + obj.h;
    result.m = m + obj.m;
    result.s = s + obj.s;

    if (result.s >= 60) {
        result.m++;
        result.s -= 60;
    }

    if (result.m >= 60) {
        result.h++;
        result.m -= 60;
    }
            
    return result;
}

timer timer::operator-= (timer const &obj) {

    h -= obj.h;
    m -= obj.m;
    s -= obj.s;

    if (h < 0) {
        h = 0;
        m -= abs(h) * 60;
    }

    if (m < 0) {
        m = 0;
        s -= abs(m) * 60;
    }

    if (s < 0) {
        s = 0;
    }
  
    return *this;
}

timer timer::operator- (timer const &obj) {

    timer result;

    result.h = h - obj.h;
    result.m = m - obj.m;
    result.s = s - obj.s;

    if (result.h < 0) {
        result.h = 0;
        result.m -= abs(result.h) * 60;
    }

    if (result.m < 0) {
        result.m = 0;
        result.s -= abs(result.m) * 60;
    }

    if (result.s < 0) {
        result.s = 0;
    }

    return result;
}

timer timer::operator/ (int divisor) {

    timer result;

    double time;

    time = 3600 * h + 60 * m + s;

    time /= divisor;

    result.h = time / 3600;
    result.m = (time - (result.h*3600)) / 60;
    result.s = (time - ((result.h*3600) + (result.m*60)));

    return result;
}
 
timer timer::operator/= (int divisor) {

    double time;

    time = 3600 * h + 60 * m + s;

    time /= divisor;

    h = time / 3600;
    m = (time - (h*3600)) / 60;
    s = (time - ((h*3600) + (m*60)));

    return *this;
}

bool timer::operator< (timer const &obj) {
    double time_1 = 3600 * h + 60 * m + s;
    double time_2 = 3600 * obj.h + 60 * obj.m + obj.s;

    return time_1 < time_2;
}

ostream& operator<<(ostream& os, const timer& dt) {
    os << dt.h << ":" << dt.m << ":" << dt.s << endl;
    return os;
}

timer::operator double () {
    return 3600 * h + 60 * m + s;
}
