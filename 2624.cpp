#include <cstdio>
using namespace std;

int t, k;
int d[101][10001];
int p[101], n[101];

int main() {
    scanf("%d %d", &t, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &p[i], &n[i]);
    }

    d[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= t; j++) {
            if (d[i - 1][j]) {
                for (int c = 0; c <= n[i] && j + p[i] * c <= t; c++) {
                    d[i][j + p[i] * c] += d[i - 1][j];
                }
            }
        }
    }

    printf("%d\n", d[k][t]);

    return 0;
}