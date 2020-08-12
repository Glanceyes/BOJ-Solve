#include <cstdio>
using namespace std;

#define N_MAX 101
#define INF 987654321

int n, m;
int d[N_MAX][N_MAX];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        d[x][y] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (d[i][j] == INF && d[j][i] == INF) {
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}