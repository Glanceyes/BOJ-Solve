#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pqRoad = tuple<int, int, int>;

#define MAX_VALUE (int)1e9

struct Road {
    int dest, length, toll;
    Road(int d, int l, int t) {
        dest = d; length = l; toll = t;
    }
};

int k, n, r;
int dist[101][10001];
vector<Road> road[101];

void find() {
    priority_queue<pqRoad, vector<pqRoad>, greater<pqRoad>> pq;
    for (int i = 0; i < (int)road[1].size(); i++) {
        auto x = road[1][i];
        if (x.toll <= k) {
            pq.push({ x.length, x.toll, x.dest });
            dist[x.dest][x.toll] = x.length;
        }
    }
    dist[1][0] = 0;

    while (!pq.empty()) {
        int cur_dist, cur_toll, cur_pos;
        tie(cur_dist, cur_toll, cur_pos) = pq.top(); pq.pop();
        if (dist[cur_pos][cur_toll] < cur_dist) continue;

        for (int i = 0; i < (int)road[cur_pos].size(); i++) {
            auto x = road[cur_pos][i];
            int sum_toll = cur_toll + x.toll;
            int sum_dist = cur_dist + x.length;
            if (sum_toll <= k) {
                if (dist[x.dest][sum_toll] > sum_dist) {
                    dist[x.dest][sum_toll] = sum_dist;
                    pq.push({ sum_dist, sum_toll, x.dest });
                }
            }
        }
    }

}

int main() {
    scanf("%d %d %d", &k, &n, &r);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dist[i][j] = MAX_VALUE;
        }
    }

    for (int i = 0; i < r; i++) {
        int s, d, l, t;
        scanf("%d %d %d %d", &s, &d, &l, &t);
        road[s].push_back({ d, l, t });
    }

    find();
    int ans = MAX_VALUE;
    for (int i = 0; i <= k; i++) {
        if (dist[n][i] < ans) {
            ans = dist[n][i];
        }
    }
    printf("%d\n", ans);

    return 0;
}