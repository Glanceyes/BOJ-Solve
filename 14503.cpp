#include <cstdio>

using namespace std;

int n, m, r, c, d;
int map[50][50];
bool visit[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    int result = 0;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            scanf("%d", &map[i][j]);
        }
    }

    visit[r][c] = 1; result += 1;

    while (1) {
        int cnt = 0;
        for (; cnt < 4; cnt += 1) {
            d = (d - 1 >= 0) ? (d - 1) : 3;
            if (r + dx[d] >= 0 && r + dx[d] < n &&
                c + dy[d] >= 0 && c + dy[d] < m) {
                if (!map[r + dx[d]][c + dy[d]] &&
                    !visit[r + dx[d]][c + dy[d]]) {
                    r += dx[d]; c += dy[d];
                    visit[r][c] = 1; result += 1; break;
                }
            }
        }
        if (cnt == 4) {
            int dir = (d < 2) ? (d + 2) : (d - 2);
            if (r + dx[dir] >= 0 && r + dx[dir] < n &&
                c + dy[dir] >= 0 && c + dy[dir] < m) {
                if (!map[r + dx[dir]][c + dy[dir]]) {
                    r += dx[dir]; c += dy[dir];
                    continue;
                }
            }
            break;
        }
    }

    printf("%d\n", result);

    return 0;
}