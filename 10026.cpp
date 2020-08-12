#include <cstdio>
#include <queue>
using namespace std;

int n, num[2];
char mat[101][101];
int visit[101][101][2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int x, int y, bool possible) {
    char color = mat[x][y];
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y][possible] = num[possible];
    
    while (!q.empty()) {
        queue<pair<int, int>> next_q;
        while (!q.empty()) {
            int nx, ny, tx, ty;
            nx = q.front().first;
            ny = q.front().second; q.pop();

            if (possible || (!possible && color == 'B')) {
                for (int i = 0; i < 4; i += 1) {
                    tx = nx + dx[i];
                    ty = ny + dy[i];
                    if (tx >= 0 && tx < n &&
                        ty >= 0 && ty < n) {
                        if (mat[tx][ty] == color && !visit[tx][ty][possible]) {
                            visit[tx][ty][possible] = num[possible];
                            next_q.push(make_pair(tx, ty));
                        }
                    }
                }
            }
            else {
                for (int i = 0; i < 4; i += 1) {
                    tx = nx + dx[i];
                    ty = ny + dy[i];
                    if (tx >= 0 && tx < n &&
                        ty >= 0 && ty < n) {
                        if ((mat[tx][ty] == 'R' ||
                            mat[tx][ty] == 'G') &&
                            !visit[tx][ty][possible]) {
                            visit[tx][ty][possible] = num[possible];
                            next_q.push(make_pair(tx, ty));
                        }
                    }
                }
            }
        }
        q = next_q;
    }

}

int main() {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            mat[i][j] = getchar();
        }
        getchar();
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            for (int k = 0; k < 2; k += 1) {
                if (!visit[i][j][k]) {
                    num[k] += 1; bfs(i, j, k);
                }
            }
        }
    }


    printf("%d %d\n", num[1], num[0]);

    return 0;
}