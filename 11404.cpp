#include <cstdio>
using namespace std;

#define N_MAX 101
#define INF 3000000000

int n, m;

long long dist[N_MAX][N_MAX];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (dist[a][b] > c) {
            dist[a][b] = c;
        }
    }

    for (int m = 1; m <= n; m++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (dist[i][j] > dist[i][m] + dist[m][j]) {
                    dist[i][j] = dist[i][m] + dist[m][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                printf("0 ");
            }
            else {
                printf("%lld ", dist[i][j]);
            }
        }
        printf("\n");
    }


    return 0;
}