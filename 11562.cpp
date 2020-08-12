#include <cstdio>
#include <algorithm>
using namespace std;

#define N_MAX 251
#define INF 0x3f3f3f3f

int n, m, k;
int dst[N_MAX][N_MAX];

int main() {
    scanf("%d %d", &n, &m);
    fill(dst[0], dst[0] + N_MAX * N_MAX, INF);
    for (int i = 1; i <= n; i++) {
        dst[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, b; scanf("%d %d %d", &u, &v, &b);
        if (b) {
            dst[u][v] = 0; dst[v][u] = 0;
        }
        else {
            dst[u][v] = 0; dst[v][u] = 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dst[i][j] > dst[i][k] + dst[k][j]) {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int s, e; scanf("%d %d", &s, &e);
        if (dst[s][e] != INF) {
            printf("%d\n", dst[s][e]);
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}