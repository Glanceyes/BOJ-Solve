#include <cstdio>
#include <queue>

using namespace std;

#define MAX 1000

int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool map[MAX + 1][MAX + 1];
int visit[MAX + 1][MAX + 1][2];

int bfs() {
    queue<pair<pair<int, int>, bool>> q;
    q.push(make_pair(make_pair(1, 1), 0));
    visit[1][1][0] = 1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool crush = q.front().second;
        if (x == n && y == m) return 1;
        q.pop();
        for (int i = 0; i < 4; i += 1) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if (tmpx > 0 && tmpx <= n &&
                tmpy > 0 && tmpy <= m) {
                if (map[tmpx][tmpy] && !crush) {
                    int tmpvst = visit[x][y][0] + 1;
                    if (visit[tmpx][tmpy][1] > tmpvst) {
                        visit[tmpx][tmpy][1] = tmpvst;
                        q.push(make_pair(make_pair(tmpx, tmpy), true));
                    }
                }
                else if (!map[tmpx][tmpy]) {
                    int tmpvst;
                    if (crush) tmpvst = visit[x][y][1] + 1;
                    else tmpvst = visit[x][y][0] + 1;
                    if (visit[tmpx][tmpy][(int)crush] > tmpvst) {
                        visit[tmpx][tmpy][(int)crush] = tmpvst;
                        if (crush) {
                            q.push(make_pair(make_pair(tmpx, tmpy), true));
                        }
                        else {
                            q.push(make_pair(make_pair(tmpx, tmpy), false));
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    getchar();

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            int temp = (int)(getchar() - '0');
            if (temp) map[i][j] = true;
            else map[i][j] = false;
            visit[i][j][0] = visit[i][j][1] = MAX * MAX;
        }
        getchar();
    }

    if (bfs()) {
        printf("%d\n", ((visit[n][m][1] > visit[n][m][0]) ? (visit[n][m][0]) : (visit[n][m][1])));
    }
    else {
        printf("-1\n");
    }

    return 0;
}