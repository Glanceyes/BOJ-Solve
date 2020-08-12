#include <cstdio>
#include <cmath>
using namespace std;

#define abs(x) (((x) >= 0) ? (x) : -(x))

struct dot {
    double x;
    double y;
    double z;
};

dot A, B, C;

double distance(dot a, dot b) {
    double result = 0;
    double d1 = (a.x - b.x);
    double d2 = (a.y - b.y);
    double d3 = (a.z - b.z);
    result = sqrt((d1 * d1 + d2 * d2 + d3 * d3));
    return result;
}

int main() {
    double ix, iy, iz, dx, dy, dz;
    for (int i = 0; i < 3; i += 1) {
        scanf("%lf %lf %lf", &ix, &iy, &iz);
        switch (i) {
        case 0:
            A.x = ix; A.y = iy; A.z = iz; break;
        case 1:
            B.x = ix; B.y = iy; B.z = iz; break;
        case 2:
            C.x = ix; C.y = iy; C.z = iz; break;
        }
    }

    dx = B.x - A.x; dy = B.y - A.y; dz = B.z - A.z;

    double left = 0.0, right = 1.0, ans = 0.0;

    while (abs(right - left) > 1e-9) {
        double m1 = left + (right - left) / 3;
        double m2 = right - (right - left) / 3;
        dot s1, s2; double ans1, ans2;
        s1.x = A.x + m1 * dx; s2.x = A.x + m2 * dx;
        s1.y = A.y + m1 * dy; s2.y = A.y + m2 * dy;
        s1.z = A.z + m1 * dz; s2.z = A.z + m2 * dz;
        if ((ans1 = distance(s1, C)) > (ans2 = distance(s2, C))) {
            left = m1; ans = ans2;
        }
        else {
            right = m2; ans = ans1;
        }
    }

    printf("%.8f\n", ans);

    return 0;
}