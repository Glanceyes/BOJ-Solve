#include <cstdio>

using namespace std;

#define MAX 1000
#define LARGER(x, y) (((x) > (y)) ? (x) : (y))

int n, m;
int s[MAX + 1][MAX + 1];
int d[MAX + 1][MAX + 1];

int find(int x, int y) {
    if (x < 1 || y < 1) {
        return 0;
    }
    if (d[x][y] != -1) {
        return d[x][y];
    }

    d[x][y] = LARGER(find(x - 1, y), find(x, y - 1)) + s[x][y];
    return d[x][y];
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            scanf("%d", &s[i][j]);
            d[i][j] = -1;
        }
    }

    printf("%d\n", find(n, m));

    return 0;
}