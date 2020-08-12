#include <cstdio>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

int n, m, k;
int map[1000][1000];
int DAY[1000][1000][11];
int NIGHT[1000][1000][11];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs() {
    queue<tuple<int, int, int, int>> day, night;
    day.push(make_tuple(0, 0, 0, 1));
    DAY[0][0][0] = 1;
    NIGHT[0][0][0] = 2;

    while (!day.empty() || !night.empty()) {
        int x, y, crash, route;
        if (!day.empty()) {
            tie(x, y, crash, route) = day.front();
            if (DAY[x][y][crash] > route) {
                DAY[x][y][crash] = route;
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
                    if (NIGHT[nx][ny][t_crash] == -1 ||
                        (route + 1 < NIGHT[nx][ny][t_crash])) {
                        NIGHT[nx][ny][t_crash] = route + 1;
                        night.push(make_tuple(nx, ny, t_crash, route + 1));
                    }
                }
            }
        }
        if (!night.empty()) {
            tie(x, y, crash, route) = night.front();
            if (NIGHT[x][y][crash] > route) {
                NIGHT[x][y][crash] = route;
            }
            night.pop();
            day.push(make_tuple(x, y, crash, route + 1));
            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (!map[nx][ny]) {
                        if (DAY[nx][ny][crash] == -1 ||
                            (route + 1 < DAY[nx][ny][crash])) {
                            DAY[nx][ny][crash] = route + 1;
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

    memset(DAY, -1, sizeof(DAY));
    memset(NIGHT, -1, sizeof(NIGHT));

    bfs();

    int ans = -1;
    for (int i = 0; i <= k; i += 1) {
        if (ans == -1 || 
            (DAY[n - 1][m - 1][i] != -1 && DAY[n - 1][m - 1][i] < ans)) {
            ans = DAY[n - 1][m - 1][i];
        }
        if (ans == -1 || 
            (NIGHT[n - 1][m - 1][i] != -1 && NIGHT[n - 1][m - 1][i] < ans)) {
            ans = NIGHT[n - 1][m - 1][i];
        }
    }
    printf("%d\n", ans);

    return 0;
}