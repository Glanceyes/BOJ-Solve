#include <cstdio>
using namespace std;

#define N_MAX 1024

int n, m;
int mat[N_MAX + 1][N_MAX + 1];
int tree[N_MAX * 4 + 1][N_MAX * 4 + 1];

void update(int x, int y, int val) {
    for (int i = x; i <= N_MAX * 4; i += i & -i) {
        for (int j = y; j <= N_MAX * 4; j += j & -j) {
            tree[i][j] += val;
        }
    }
}

int sum(int x, int y) {
    int result = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            result += tree[i][j];
        }
    }
    return result;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
            update(i, j, mat[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        int w; scanf("%d", &w);
        if (w == 0) {
            int x, y, c; scanf("%d %d %d", &x, &y, &c);
            update(x, y, c - mat[x][y]);
            mat[x][y] = c;
        }
        else if (w == 1) {
            int x1, y1, x2, y2, ans = 0;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ans = sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
            printf("%d\n", ans);
        }
    }
}