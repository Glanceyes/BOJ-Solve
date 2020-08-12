#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
using Edge = pair<int, int>;

int tc, n, m, t;
int s, g, h, a, b, d;

int dsx[2001];
int dgx[2001];
int dhx[2001];
vector<int> cddt;
vector<Edge> edge[2001];

void dijkstra(int start, int *dist) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({ 0, start }); dist[start] = 0;

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_pos = pq.top().second; pq.pop();
        if (dist[cur_pos] < cur_dist) continue;

        for (int i = 0; i < (int)edge[cur_pos].size(); i++) {
            int neigh_pos = edge[cur_pos][i].first;
            int neigh_dist = dist[cur_pos] + edge[cur_pos][i].second;

            if (dist[neigh_pos] > neigh_dist) {
                dist[neigh_pos] = neigh_dist;
                pq.push({ neigh_dist, neigh_pos });
            }
        }
    }
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        int ghcost = 0;
        scanf("%d %d %d", &n, &m, &t);
        for (int i = 1; i <= n; i++) {
            edge[i].clear(); 
            dsx[i] = dgx[i] = dhx[i] = INF;
        }
        cddt.clear();
        scanf("%d %d %d", &s, &g, &h);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &d);
            edge[a].push_back({ b, d });
            edge[b].push_back({ a, d });
            if ((a == g && b == h) || (a == h && b == g)) {
                ghcost = d;
            }
        }
        for (int i = 0; i < t; i++) {
            int x; scanf("%d", &x);
            cddt.push_back(x);
        }
        dijkstra(s, dsx);
        dijkstra(g, dgx);
        dijkstra(h, dhx);
        sort(cddt.begin(), cddt.end());
        for (int i = 0; i < (int)cddt.size(); i++) {
            if ((dsx[cddt[i]] == dsx[g] + ghcost + dhx[cddt[i]]) ||
                (dsx[cddt[i]] == dsx[h] + ghcost + dgx[cddt[i]])) {
                printf("%d ", cddt[i]);
            }
        }
        printf("\n");
    }

    return 0;
}