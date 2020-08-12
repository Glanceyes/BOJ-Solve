#include <cstdio>
using namespace std;

#define V_MAX 401
#define INF 987654321

int v, e;
int dist[V_MAX][V_MAX];

int main() {
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
    }

    int ans = -1;
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if (i == j && (ans == -1 || ans > dist[i][j])) {
                        ans = dist[i][j];
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}