#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using edge = pair<int, pair<int, int>>;

#define N_MAX 125
#define INF 987654321

int n;
int d[N_MAX][N_MAX];
int map[N_MAX][N_MAX];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void go() {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ map[0][0], {0, 0} }); d[0][0] = map[0][0];

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cur_d = pq.top().first;
        pq.pop();

        if (cur_d > d[x][y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (d[nx][ny] > cur_d + map[nx][ny]) {
                d[nx][ny] = cur_d + map[nx][ny];
                pq.push({ d[nx][ny], {nx, ny} });
            }
        }
    }
}

int main() {
    int cnt = 0;
    while (1) {
        scanf("%d", &n); 
        if (!n) break;
        cnt += 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
                d[i][j] = INF;
            }
        }
        go();
        printf("Problem %d: %d\n", cnt, d[n - 1][n - 1]);
    }

    return 0;
}