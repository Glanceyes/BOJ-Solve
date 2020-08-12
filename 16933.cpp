#include <cstdio>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int n, m, k, result = -1;
int map[1000][1000];
bool DAY[1000][1000][11];
bool NIGHT[1000][1000][11];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs() {
    queue<tuple<int, int, int, int>> day, night;
    day.push(make_tuple(0, 0, 0, 1));
    DAY[0][0][0] = NIGHT[0][0][0] = true;

    while (!day.empty() || !night.empty()) {
        int x, y, crash, route;
        if (!day.empty()) {
            tie(x, y, crash, route) = day.front();
            if (x == n - 1 && y == m - 1 && (
                result == -1 || route < result)) {
                result = route;
            }
            day.pop();
            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int t_crash;
                    // 인접한 칸이 벽이면
                    if (map[nx][ny]) {
                        if (crash + 1 > k) { continue; }
                        t_crash = crash + 1;
                    }
                    // 인접한 칸이 빈 방이면
                    else {
                        t_crash = crash;
                    }
                    if (!NIGHT[nx][ny][t_crash]) {
                        NIGHT[nx][ny][t_crash] = true;
                        night.push(make_tuple(nx, ny, t_crash, route + 1));
                    }
                }
            }
        }
        if (!night.empty()) {
            tie(x, y, crash, route) = night.front();
            if (x == n - 1 && y == m - 1 && (
                result == -1 || route < result)) {
                result = route;
            }
            night.pop();
            day.push(make_tuple(x, y, crash, route + 1));
            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (!map[nx][ny]) {
                        if (!DAY[nx][ny][crash]) {
                            DAY[nx][ny][crash] = true;
                            day.push(make_tuple(nx, ny, crash, route + 1));
                        }
                    }
                }
            }
        }
    }
}
int main() {
    scanf("%d %d %d\n", &n, &m, &k);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            char c = getchar();
            map[i][j] = (int)(c - '0');
        }
        getchar();
    }

    memset(DAY, false, sizeof(DAY));
    memset(NIGHT, false, sizeof(NIGHT));

    bfs();
    printf("%d\n", result);

    return 0;
}