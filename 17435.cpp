#include <cstdio>
using namespace std;

#define D_MAX 19
#define V_MAX 500001

int v[V_MAX][D_MAX];

int main() {
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &v[i][0]);
    }

    for (int j = 1; j < D_MAX; j++) {
        for (int i = 1; i <= m; i++) {
            v[i][j] = v[v[i][j - 1]][j - 1];
        }
    }
    int Q; scanf("%d", &Q);
    while (Q--) {
        int n, x; scanf("%d %d", &n, &x);
        for (int i = 0; i < D_MAX; i++) {
            if (n % 2) {
                x = v[x][i];
            }
            n /= 2;
        }
        printf("%d\n", x);
    }

    return 0;
}