#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX 50

int r, c, dsx, dsy;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int visit[MAX + 1][MAX + 1];
char map[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
vector<pair<int, int>> water;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> w;
    q.push(make_pair(x, y));
    check[x][y] = true;

    for (unsigned int i = 0; i < water.size(); i += 1) {
        int wx = water[i].first;
        int wy = water[i].second;
        w.push(make_pair(wx, wy));
        check[wx][wy] = true;
    }

    while (!q.empty()) {
        queue<pair<int, int>> nxtw;
        while(!w.empty()) {
            int wx = w.front().first;
            int wy = w.front().second;
            w.pop();
            for (int j = 0; j < 4; j += 1) {
                int tmpwx = wx + dx[j];
                int tmpwy = wy + dy[j];
                if (tmpwx > 0 && tmpwx <= r &&
                    tmpwy > 0 && tmpwy <= c &&
                    !check[tmpwx][tmpwy] &&
                        (map[tmpwx][tmpwy] == '.' ||
                         map[tmpwx][tmpwy] == 'S')
                    ) {
                    check[tmpwx][tmpwy] = true;
                    nxtw.push(make_pair(tmpwx, tmpwy));
                }
            }
        }
        w = nxtw;

        queue<pair<int, int>> nxtq;
        while (!q.empty()) {
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j += 1) {
                int tmpqx = qx + dx[j];
                int tmpqy = qy + dy[j];
                if (tmpqx > 0 && tmpqx <= r &&
                    tmpqy > 0 && tmpqy <= c &&
                    !check[tmpqx][tmpqy] &&
                        (map[tmpqx][tmpqy] == '.' ||
                         map[tmpqx][tmpqy] == 'D')
                    ) {
                    check[tmpqx][tmpqy] = true;
                    visit[tmpqx][tmpqy] = visit[qx][qy] + 1;
                    if (tmpqx == dsx && tmpqy == dsy) return 1;
                    nxtq.push(make_pair(tmpqx, tmpqy));
                }
            }
        }
        q = nxtq;
    }
    return 0;
}

int main() {
    int sx, sy; sx = sy = 1;
    scanf("%d %d", &r, &c); getchar();

    for (int i = 1; i <= r; i += 1) {
        for (int j = 1; j <= c; j += 1) {
            map[i][j] = getchar();
            switch (map[i][j]) {
            case '*':
                water.push_back(make_pair(i, j)); break;
            case 'S':
                sx = i, sy = j; break;
            case 'D':
                dsx = i, dsy = j; break;
            default: break;
            }
        }
        getchar();
    }

    if (bfs(sx, sy)) {
        printf("%d\n", visit[dsx][dsy]);
    }
    else {
        printf("KAKTUS\n");
    }

    return 0;
}