#include <cstdio>
#include <queue>
using namespace std;

int n, m, result;
int map[8][8];
bool visit[8][8];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visit[sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second; q.pop();
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m) {
                if (!visit[nx][ny] && map[nx][ny] != 1) {
                    visit[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void find(int idx, int si) {
    if (idx == 3) {
        int temp = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                visit[i][j] = false;
            }
        }
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (map[i][j] == 2 && !visit[i][j]) {
                    bfs(i, j);
                }
            }
        }
        
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (map[i][j] == 0 && !visit[i][j]) {
                    temp += 1;
                }
            }
        }

        if (result < temp) {
            result = temp;
        }

        return;
    }
    for (int i = si; i < n * m; i += 1) {
        if (!map[i / m][i % m]) {
            map[i / m][i % m] = 1;
            find(idx + 1, si + 1);
            map[i / m][i % m] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            scanf("%d", &map[i][j]);
        }
    }

    find(0, 0);

    printf("%d\n", result);

    return 0;
}