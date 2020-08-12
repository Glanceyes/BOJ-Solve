#include <cstdio>
#include <queue>

using namespace std;

#define MAX 100

int w, h;
int mirror[MAX][MAX][4];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char map[MAX][MAX];

void find(int sx, int sy) {
    queue <pair<pair<int, int>, int>> q;
    for (int i = 0; i < 4; i += 1) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if (tx >= 0 && tx < h &&
            ty >= 0 && ty < w && map[tx][ty] != '*') {
            mirror[tx][ty][i] = 0;
            q.push(make_pair(make_pair(tx, ty), i));
        }
    }
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second; q.pop();
        for (int i = 0; i < 4; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int mir = 0;
            if (nx >= 0 && nx < h && 
                ny >= 0 && ny < w && map[nx][ny] != '*') {
                // 진행해왔던 방향과 정반대로 가는 경우는 불가능
                if ((i % 2 == dir % 2) && (i != dir)) continue;
                // 거울 놓아서 90도로 회전하여 이동할 수 있는 경우
                if (i % 2 != dir % 2) {
                    mir = 1;
                }
                if (mirror[nx][ny][i] == -1 ||
                    mirror[nx][ny][i] > mirror[x][y][dir] + mir) {
                    mirror[nx][ny][i] = mirror[x][y][dir] + mir;
                    q.push(make_pair(make_pair(nx, ny), i));
                }
            }
        }
    }

    return;
}

int main() {
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1;
    scanf("%d %d\n", &w, &h);

    for (int i = 0; i < h; i += 1) {
        for (int j = 0; j < w; j += 1) {
            map[i][j] = getchar();
            if (map[i][j] == 'C') {
                if (x1 == -1 && y1 == -1) {
                    x1 = i;y1 = j;
                }
                else {
                    x2 = i;y2 = j;
                }
            }
            for (int k = 0; k < 4; k += 1) {
                mirror[i][j][k] = -1;
            }
        }
        getchar();
    }
    
    find(x1, y1);
    int min = -1;

    for (int i = 0; i < 4; i += 1) {
        if (mirror[x2][y2][i] == -1) continue;
        if (min == -1 || min > mirror[x2][y2][i]) {
            min = mirror[x2][y2][i];
        }
    }
    printf("%d\n", min);

    return 0;
}