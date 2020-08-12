#include <cstdio>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;

#define MAX 100

int m, n, h;
int tomato[MAX][MAX][MAX];
int day[MAX][MAX][MAX];
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x, y, z; tie(z, x, y) = q.front();
        int tempday = day[z][x][y]; q.pop();

        for (int i = 0; i < 6; i += 1) {
            int tempx = x + dx[i];
            int tempy = y + dy[i];
            int tempz = z + dz[i];
            if (tempx >= 0 && tempx < n && 
                tempy >= 0 && tempy < m &&
                tempz >= 0 && tempz < h) {
                if (day[tempz][tempx][tempy] == -1 && 
                    tomato[tempz][tempx][tempy] == 0) {
                    tomato[tempz][tempx][tempy] = 1;
                    day[tempz][tempx][tempy] = tempday + 1;
                    q.push(make_tuple(tempz, tempx, tempy));
                }
            }
        }
    }
    return;
}

int main() {
    int maxValue = 0;
    bool flag = false;

    scanf("%d %d %d", &m, &n, &h);

    for (int i = 0; i < h; i += 1) {
        for (int j = 0; j < n; j += 1) {
            for (int k = 0; k < m; k += 1) {
                scanf("%d", &tomato[i][j][k]);
                if (tomato[i][j][k] == 1) {
                    flag = true;
                    q.push(make_tuple(i, j, k));
                    day[i][j][k] = 0;
                }
                else {
                    day[i][j][k] = -1;
                }
            }
        }
    }

    bfs();
    if (!flag) {
        printf("-1\n"); return 0;
    }

    for (int i = 0; i < h; i += 1) {
        for (int j = 0; j < n; j += 1) {
            for (int k = 0; k < m; k += 1) {
                if (tomato[i][j][k] == 0) {
                    flag = false;
                }
                if (maxValue < day[i][j][k]) {
                    maxValue = day[i][j][k];
                }
            }
        }
    }

    if (!flag) {
        printf("-1\n");
    }
    else {
        printf("%d\n", maxValue);
    }

    return 0;
}