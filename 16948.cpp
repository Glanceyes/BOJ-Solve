#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int n;
int visit[200][200];
int r1, c1, r2, c2;
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

void find() {
    queue<pair<int, int>> q;
    q.push(make_pair(r1, c1));
    visit[r1][c1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 6; i += 1) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + 1) {
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    memset(visit, -1, sizeof(visit));
    find();
    printf("%d\n", visit[r2][c2]);

    return 0;
}