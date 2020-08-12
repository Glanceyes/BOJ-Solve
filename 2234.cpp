#include <cstdio>
#include <queue>
using namespace std;

int n, m, num, area, rm;
int map[50][50];
int big[2500 + 1];
int visit[50][50];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void find(int x, int y, int room) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = room;

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second; 
        big[room] += 1; q.pop();

        for (int i = 0, j = 1; i < 4; i += 1, j = (j << 1)) {
            if (!(map[nx][ny] & j)) {
                int tx = nx + dx[i];
                int ty = ny + dy[i];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (!visit[tx][ty]) {
                        visit[tx][ty] = room;
                        q.push(make_pair(tx, ty));
                    }
                }
            }
        }
    }

    
    if (area < big[room]) {
        area = big[room];
    }

    return;
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (!visit[i][j]) {
                num += 1; find(i, j, num);
            }
        }
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            for (int k = 0, l = 1; k < 4; k += 1, l = (l << 1)) {
                if (map[i][j] & l) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if ((visit[i][j] != visit[tx][ty]) &&
                            (rm < big[visit[i][j]] + big[visit[tx][ty]])) {
                            rm = big[visit[i][j]] + big[visit[tx][ty]];
                        }
                    }
                }
            }
        }
    }

    printf("%d\n%d\n%d\n", num, area, rm);

    return 0;
}