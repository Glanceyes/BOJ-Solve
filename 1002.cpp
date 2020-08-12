#include <cstdio>
using namespace std;

int t;

void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
    return;
}

double distance(double x1, double x2, double y1, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    scanf("%d", &t);
    
    while (t--) {
        double x1, x2, y1, y2, r1, r2;
        scanf("%lf %lf %lf", &x1, &y1, &r1);
        scanf("%lf %lf %lf", &x2, &y2, &r2);

        if (x1 == x2 && y1 == y2 && r1 == r2) {
            printf("-1\n"); continue;
        }

        if (r1 < r2) {
            swap(x1, x2); swap(y1, y2); swap(r1, r2);
        }
        
        double d = distance(x1, x2, y1, y2);

        if (r1 * r1 >= d) {
            double temp = (r1 - r2) * (r1 - r2);
            if (d < temp) {
                printf("0\n");
            }
            else if (d == temp) {
                printf("1\n");
            }
            else {
                printf("2\n");
            }
        }
        else {
            double temp = (r1 + r2) * (r1 + r2);
            if (d > temp) {
                printf("0\n");
            }
            else if (d == temp) {
                printf("1\n");
            }
            else {
                printf("2\n");
            }
        }
    }


    return 0;
}