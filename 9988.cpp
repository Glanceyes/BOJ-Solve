#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using edge = pair<long long, int>;

const int N_MAX = 250;
const long long INF = 25000000001;

int n, m;
int prv[N_MAX + 1];
long long dst[N_MAX + 1];
vector<edge> edges[N_MAX + 1];

long long EDGES[N_MAX + 1][N_MAX + 1];

long long go() {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ 0, 1 }); dst[1] = 0;

    while (!pq.empty()) {
        int cur_pos = pq.top().second;
        long long cur_dst = pq.top().first;
        pq.pop();

        if (dst[cur_pos] < cur_dst) continue;

        for (auto next : edges[cur_pos]) {
            int next_pos = next.second;
            long long next_dst = next.first + cur_dst;

            if (dst[next_pos] > next_dst) {
                dst[next_pos] = next_dst;
                prv[next_pos] = cur_pos;
                pq.push({ next_dst, next_pos });
            }
        }
    }

    return dst[n];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; long long l;
        scanf("%d %d %lld", &a, &b, &l);
        edges[a].push_back({ l, b });
        edges[b].push_back({ l, a });

        EDGES[a][b] = EDGES[b][a] = l;
    }

    fill(dst, dst + N_MAX + 1, INF);
    fill(prv, prv + N_MAX + 1, 0);

    long long ans1 = go();
    long long max_weight = 0;

    int u = 0, v = 0;
    for (int i = n; i != 1; i = prv[i]) {
        if (max_weight < EDGES[i][prv[i]]) {
            max_weight = EDGES[i][prv[i]];
            u = i; v = prv[i];
        }
    }

    EDGES[u][v] *= 2;
    EDGES[v][u] *= 2;

    for (int i = 0; i < (int)edges[u].size(); i++) {
        if (edges[u][i].second == v) {
            edges[u][i].first *= 2;
        }
    }

    for (int i = 0; i < (int)edges[v].size(); i++) {
        if (edges[v][i].second == u) {
            edges[v][i].first *= 2;
        }
    }

    fill(dst, dst + N_MAX + 1, INF);
    fill(prv, prv + N_MAX + 1, 0);

    long long ans2 = go();
    printf("%lld\n", ans2 - ans1);

    return 0;
}