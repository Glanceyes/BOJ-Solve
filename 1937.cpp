#include <cstdio>
using namespace std;

int n, day;
int forest[500][500];
int visit[500][500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int find(int x, int y) {
    if (visit[x][y]) {
        return visit[x][y];
    }
    int max = 1, temp = 0;

    for (int i = 0; i < 4; i += 1) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (forest[nx][ny] < forest[x][y]) {
                if (max < (temp = find(nx, ny) + 1)) {
                    max = temp;
                }
            }
        }
    }
    return (visit[x][y] = max);
}

int main() {
    int temp = 0; scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            scanf("%d", &forest[i][j]);
        }
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (!visit[i][j]) {
                if (day < (temp = find(i, j))) {
                    day = temp;
                }
            }
        }
    }

    printf("%d\n", day);

    return 0;
}