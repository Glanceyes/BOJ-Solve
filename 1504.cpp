#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using edge = pair<long long, int>;

#define MAX_VALUE 20000000000

int n, e, v1, v2;
long long dis[3][801];
vector<edge> edges[801];

void find(int idx, int start) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ 0, start });
    long long* dist = dis[idx];
    dist[start] = 0;

    while (!pq.empty()) {
        long long cur_dist = pq.top().first;
        int cur_pos = pq.top().second; pq.pop();

        if (dist[cur_pos] < cur_dist) continue;

        for (int i = 0; i < (int)edges[cur_pos].size(); i++) {
            int neigh_pos = edges[cur_pos][i].second;
            long long neigh_dist = cur_dist + edges[cur_pos][i].first;

            if (dist[neigh_pos] > neigh_dist) {
                dist[neigh_pos] = neigh_dist;
                pq.push({ neigh_dist, neigh_pos });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &e);

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = MAX_VALUE;
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b; long long c;
        scanf("%d %d %lld", &a, &b, &c);
        edges[a].push_back({ c, b });
        edges[b].push_back({ c, a });
    }

    scanf("%d %d", &v1, &v2);
    long long ans1, ans2;
    ans1 = ans2 = MAX_VALUE;

    find(0, 1); find(1, v1); find(2, v2);
    if (dis[0][v1] != MAX_VALUE && dis[1][v2] != MAX_VALUE && dis[2][n] != MAX_VALUE) {
        ans1 = dis[0][v1] + dis[1][v2] + dis[2][n];
    }
    if (dis[0][v2] != MAX_VALUE && dis[2][v1] != MAX_VALUE && dis[1][n] != MAX_VALUE) {
        ans2 = dis[0][v2] + dis[2][v1] + dis[1][n];
    }

    if (ans1 == MAX_VALUE && ans2 == MAX_VALUE) {
        printf("-1\n");
    }
    else {
        printf("%lld\n", (ans1 < ans2) ? (ans1) : (ans2));
    }

    return 0;
}