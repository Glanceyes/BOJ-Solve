#include <cstdio>
using namespace std;

int n, k;
int d[11][11];

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 0; j <= i; j += 1) {
            if (j == 0 || j == i) {
                d[i][j] = 1;
            }
            else {
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            }
        }
    }

    printf("%d\n", d[n][k]);

    return 0;
}