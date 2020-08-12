#include <cstdio>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long d[41][2];
        int n; scanf("%d", &n);

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                d[i][j] = 0;
            }
        }

        d[0][0] = 1; d[0][1] = 0;
        d[1][0] = 0; d[1][1] = 1;

        for (int i = 2; i <= n; i++) {
            d[i][0] = d[i - 1][0] + d[i - 2][0];
            d[i][1] = d[i - 1][1] + d[i - 2][1];
        }
        printf("%lld %lld\n", d[n][0], d[n][1]);
    }

    return 0;
}