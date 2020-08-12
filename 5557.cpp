#include <cstdio>
using namespace std;

#define MAX 100

int n;
int v[MAX + 1];
long long d[MAX + 1][20 + 1];


int main() {
    long long result = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i += 1) {
        scanf("%d", &v[i]);
    }

    d[1][v[1]] = 1;

    for (int i = 2; i < n; i += 1) {
        for (int j = 0; j <= 20; j += 1) {
            if (j - v[i] >= 0) {
                d[i][j] += d[i - 1][j - v[i]];
            }
            if (j + v[i] <= 20) {
                d[i][j] += d[i - 1][j + v[i]];
            }
        }
    }

    d[n][v[n]] = d[n - 1][v[n]];

    printf("%lld\n", d[n][v[n]]);

    return 0;
}