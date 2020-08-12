#include <cstdio>
using namespace std;

#define N_MAX 30

int n;
long long d[N_MAX + 1][2 * N_MAX + 1];

int main() {
    while (1) {
        for (int i = 0; i <= N_MAX; i += 1) {
            for (int j = 0; j <= N_MAX; j += 1) {
                d[i][j] = 0;
            }
        }
        scanf("%d", &n);
        if (!n) break;
        d[n][0] = d[n - 1][1] = 1;
        for (int i = n - 1; i >= 0; i -= 1) {
            for (int j = 2 * (n - i); j >= 0; j -= 1) {
                if (i - 1 >= 0 && j + 1 <= n) {
                    d[i - 1][j + 1] += d[i][j];
                }
                if (j - 1 >= 0) {
                    d[i][j - 1] += d[i][j];
                }
            }
        }
        printf("%lld\n", d[0][0]);
    }

    return 0;
}