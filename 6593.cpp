#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
using edge = pair<int, tuple<int, int, int>>;

#define INF 987654321

int l, r, c;
char map[30][30][30];
int dist[30][30][30];

int dr[6] = {1, 0, -1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int dl[6] = {0, 0, 0, 0, 1, -1};

tuple<int, int, int> s, e;

int dijkstra() {
    priority_queue<edge, vector<edge>, greater<edge>> q;
    int sl, sr, sc, el, er, ec;
    tie(sl, sr, sc) = s;
    tie(el, er, ec) = e;
    dist[sl][sr][sc] = 0;
    q.push({ 0, s });
    while (!q.empty()) {
        int cur_l, cur_r, cur_c, cur_dist;
        cur_dist = q.top().first;
        tie(cur_l, cur_r, cur_c) = q.top().second; q.pop();
        if (dist[cur_l][cur_r][cur_c] < cur_dist) continue;
        
        for (int i = 0; i < 6; i++) {
            int next_l = cur_l + dl[i];
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            if (!(next_l >= 0 && next_l < l &&
                next_r >= 0 && next_r < r &&
                next_c >= 0 && next_c < c)) continue;
            if (map[next_l][next_r][next_c] == '#') continue;
            if (dist[next_l][next_r][next_c] > cur_dist + 1) {
                dist[next_l][next_r][next_c] = cur_dist + 1;
                if (el == next_l && er == next_r && ec == next_c) {
                    break;
                }
                q.push({ cur_dist + 1, {next_l, next_r, next_c} });
            }
        }
    }
    if (dist[el][er][ec] == INF) return -1;
    else return dist[el][er][ec];
}

int main() {
    while (1) {
        scanf("%d %d %d", &l, &r, &c);
        if (!l && !r && !c) break;
        for (int i = 0; i < l; i++) {
            getchar();
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    map[i][j][k] = getchar();
                    if (map[i][j][k] == 'S') {
                        s = { i, j, k };
                    }
                    if (map[i][j][k] == 'E') {
                        e = { i, j, k };
                    }
                    dist[i][j][k] = INF;
                }
                getchar();
            }
        }
        int result = dijkstra();
        if (result == -1) {
            printf("Trapped!\n");
        }
        else {
            printf("Escaped in %d minute(s).\n", result);
        }
    }

    return 0;
}