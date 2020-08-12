#include <cstdio>
using namespace std;

#define MIN -100000000

int n, m;
int map[1001][1001];
int visit[1002][1002][3];

int max_two(int x, int y) {
    if (x > y) {
        return x;
    }
    else {
        return y;
    }
}

int max_three(int x, int y, int z) {
    if (x > y) {
        if (x > z) {
            return x;
        }
        else {
            return z;
        }
    }
    else {
        if (y > z) {
            return y;
        }
        else {
            return z;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i <= n + 1; i += 1) {
        for (int j = 0; j <= m + 1; j += 1) {
            for (int k = 0; k < 3; k += 1) {
                visit[i][j][k] = MIN;
            }
        }
    }

    visit[1][0][1] = 0;
    for (int j = 1; j <= m; j += 1) {
        visit[1][j][0] = visit[1][j][1] = visit[1][j][2] = visit[1][j - 1][1] + map[1][j];
    }

    for (int i = 2; i <= n; i += 1) {
        visit[i][0][0] = visit[i - 1][1][0];
        visit[i][m + 1][0] = visit[i - 1][m][0];
        for (int j = 1; j <= m; j += 1) {
            visit[i][j][0] = max_three(visit[i - 1][j][0], visit[i - 1][j][1], visit[i - 1][j][2]) + map[i][j];
        }
        for (int j = 1; j <= m; j += 1) {
            visit[i][j][1] = max_two(visit[i][j - 1][0], visit[i][j - 1][1]) + map[i][j];
        }
        for (int j = m; j >= 1; j -= 1) {
            visit[i][j][2] = max_two(visit[i][j + 1][0], visit[i][j + 1][2]) + map[i][j];
        }
    }

    printf("%d\n", max_three(visit[n][m][0], visit[n][m][1], visit[n][m][2]));

    return 0;
}