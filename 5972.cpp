#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using edge = pair<int, int>;

#define V_MAX 50001
#define INF 0x3f3f3f3f

int n, m;
int dst[V_MAX];
vector<edge> edges[V_MAX];

int dijkstra(int src, int snk) {
    fill(dst, dst + V_MAX, INF);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ 0, src }); dst[src] = 0;
    while (!pq.empty()) {
        int here_dst = pq.top().first;
        int here_pos = pq.top().second; pq.pop();
        if (dst[here_pos] < here_dst) continue;

        for (auto next : edges[here_pos]) {
            int next_dst = dst[here_pos] + next.first;
            int next_pos = next.second;
            if (dst[next_pos] > next_dst) {
                dst[next_pos] = next_dst;
                pq.push({ next_dst, next_pos });
            }
        }
    }
    return dst[snk];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({ c, b });
        edges[b].push_back({ c, a });
    }
    printf("%d\n", dijkstra(1, n));

    return 0;
}