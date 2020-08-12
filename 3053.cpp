#include <cstdio>
#include <cmath>
using namespace std;

double r;
const double pi = acos(-1.0);

int main() {
    scanf("%lf", &r);

    printf("%.6lf\n", r * r * pi);
    printf("%.6lf\n", r * r * 2);

    return 0;
}