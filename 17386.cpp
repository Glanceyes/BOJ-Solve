#include <cstdio>
using namespace std;

struct Point {
    long long x;
    long long y;
};

int ccw(Point p1, Point p2, Point p3) {
    long long sum = p2.x * p3.y + p3.x * p1.y + p1.x * p2.y;
    sum -= p2.y * p3.x + p3.y * p1.x + p1.y * p2.x;
    if (sum > 0) return 1;
    if (sum < 0) return -1;
    return 0;
}

int main() {
    Point p1, p2, p3, p4;
    scanf("%lld %lld %lld %lld", &p1.x, &p1.y, &p2.x, &p2.y);
    scanf("%lld %lld %lld %lld", &p3.x, &p3.y, &p4.x, &p4.y);

    if ((ccw(p1, p2, p3) * ccw(p1, p2, p4)) < 0 &&
        (ccw(p3, p4, p1) * ccw(p3, p4, p2)) < 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }

    return 0;
}