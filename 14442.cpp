#include <cstdio>
#include <queue>
using namespace std;

#define n_max 1000
#define m_max 1000
#define k_max 10

int n, m, k;
int map[n_max + 1][m_max + 1];
int dst[n_max + 1][m_max + 1][k_max + 1];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    dst[1][1][0] = 1;
    
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second; 
        q.pop();
        
        if (nx == n && ny == m) {
            int min = -1;
            for (int i = 0; i <= k; i += 1) {
                if ((min == -1 || (min > dst[nx][ny][i])) &&
                    dst[nx][ny][i] != -1) {
                    min = dst[nx][ny][i];
                }
            }
            return min;
        }
        
        for (int i = 0; i < 4; i += 1) {
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            if (tx > 0 && tx <= n &&
                ty > 0 && ty <= m) {
                bool flag = false;
                if (map[tx][ty] == 1) {
                    for (int j = 1; j <= k; j += 1) {
                        if ((dst[tx][ty][j] == -1 ||
                            dst[tx][ty][j] > dst[nx][ny][j - 1] + 1) 
                            && dst[nx][ny][j - 1] != -1) {
                            dst[tx][ty][j] = dst[nx][ny][j - 1] + 1;
                            flag = true;
                        }
                    }
                }
                else {
                    for (int j = 0; j <= k; j += 1) {
                        if ((dst[tx][ty][j] == -1 ||
                            dst[tx][ty][j] > dst[nx][ny][j] + 1)
                            && dst[nx][ny][j] != -1) {
                            dst[tx][ty][j] = dst[nx][ny][j] + 1;
                            flag = true;
                        }
                    }
                }
                if (flag) {
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d\n", &n, &m, &k);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            map[i][j] = (int)(getchar() - '0');
            for (int m = 0; m <= k; m += 1) {
                dst[i][j][m] = -1;
            }
        }
        getchar();
    }

    printf("%d\n", bfs());

    return 0;
}