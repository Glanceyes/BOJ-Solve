#include <cstdio>
using namespace std;

#define N_MAX 501

int n, m;
bool dst[N_MAX][N_MAX];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        dst[a][b] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dst[i][j] = dst[i][j] || (dst[i][k] && dst[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dst[j][i] || dst[i][j]) cnt += 1;
        }
        if (cnt >= n - 1) ans += 1;
    }
    printf("%d\n", ans);

    return 0;
}