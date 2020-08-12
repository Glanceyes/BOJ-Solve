#include <cstdio>
using namespace std;

#define MAX 100

int n;
long long d[MAX + 1];

int main() {
    scanf("%d", &n);

    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    for (int i = 4; i <= n; i += 1) {
        long long tmp1 = d[i - 1] + 1;
        long long tmp2 = 0;
        for (int j = 1; j <= i - 3; j += 1) {
            if (tmp2 < d[j] * (i - 3 - j + 2)) {
                tmp2 = d[j] * (i - 3 - j + 2);
            }
        }

        d[i] = (tmp1 > tmp2) ? tmp1 : tmp2;
    }
    printf("%lld\n", d[n]);

    return 0;
}