#include <iostream>
using namespace std;

struct Point {
    long long x;
    long long y;
    bool operator >(const Point& p) const{
        if (this->x > p.x) {
            return true;
        }
        else if (this->x == p.x && this->y > p.y) {
            return true;
        }
        return false;
    }
    bool operator <=(const Point& p) const {
        if (this->x < p.x) {
            return true;
        }
        else if (this->x == p.x && this->y <= p.y) {
            return true;
        }
        return false;
    }
};

void swap(Point& p1, Point& p2) {
    Point temp;
    temp.x = p1.x; temp.y = p1.y;
    p1.x = p2.x; p1.y = p2.y;
    p2.x = temp.x; p2.y = temp.y;
    return;
}

int ccw(Point p1, Point p2, Point p3) {
    long long sum = 0;
    sum = p2.x * p3.y + p3.x * p1.y + p1.x * p2.y;
    sum -= (p2.y * p3.x + p3.y * p1.x + p1.y * p2.x);
    if (sum > 0) return 1;
    else if (sum < 0) return -1;
    else return 0;
}

int main() {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    int ans1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int ans2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (ans1 == 0 && ans2 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        if (p3 <= p2 && p1 <= p4) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    else if (ans1 <= 0 && ans2 <= 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
    

    return 0;
}