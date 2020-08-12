#include <cstdio>
using namespace std;

int cnt;

int main() {
    scanf("%d", &cnt);

    for (int i = 1; i <= cnt; i += 1) {
        long long x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);

        long long longest, a, b;

        if (x > y) {
            if (x > z) {
                longest = x;
                a = y; b = z;
            }
            else {
                longest = z;
                a = x; b = y;
            }
        }
        else {
            if (y > z) {
                longest = y;
                a = x; b = z;
            }
            else {
                longest = z;
                a = x; b = y;
            }
        }

        printf("Scenario #%d:\n", i);
        if ((a * a + b * b) == (longest * longest)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
        printf("\n");
    }

    return 0;
}