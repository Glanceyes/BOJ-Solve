#include <cstdio>

using namespace std;

#define MAX 1000

int n, m;
int d[MAX + 1][MAX + 1];
int s[MAX + 1][MAX + 1];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            scanf("%d", &s[i][j]);
        }
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            d[i][j] = ((d[i - 1][j] > d[i][j - 1]) ? (d[i - 1][j]) : (d[i][j - 1])) + s[i][j];
        }
    }

    printf("%d\n", d[n][m]);

    return 0;
}