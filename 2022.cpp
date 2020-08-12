#include <cstdio>
#include <cmath>
using namespace std;

#define two_min(x, y) (((x) < (y)) ? (x) : (y))
#define abs(x) ((x) >= 0 ? (x) : (y))

double x, y, c;

bool extend(double d){
    double c1 = sqrt(x * x - d * d);
    double c2 = sqrt(y * y - d * d);
    double h = (c1 * c2) / (c1 + c2);
    if (h > c) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    scanf("%lf %lf %lf", &x, &y, &c);

    double left, right;
    left = 0; right = two_min(x, y);

    while (abs(right - left) > 1e-6) {
        double mid = left + (right - left) / (double)2;
        if (extend(mid)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    printf("%.3lf\n", left);

    return 0;
}