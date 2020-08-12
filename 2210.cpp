#include <cstdio>
using namespace std;

int mat[5][5], num;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int visit[1000000];

void find(int idx, int x, int y, int sum) {
    if (idx == 6) {
        if (!visit[sum]) {
            visit[sum] = true; num += 1;
        }
        return;
    }
    for (int i = 0; i < 4; i += 1) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            find(idx + 1, nx, ny, sum * 10 + mat[nx][ny]);
        }
    }
}

int main() {
    for (int i = 0; i < 5; i += 1) {
        for (int j = 0; j < 5; j += 1) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < 5; i += 1) {
        for (int j = 0; j < 5; j += 1) {
            find(0, i, j, 0);
        }
    }

    printf("%d\n", num);

    return 0;
}