#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using edge = pair<long long, int>;

#define N_MAX 1001

int n, m, k;
priority_queue<long long> dist[N_MAX];
vector<pair<int, long long>> edges[N_MAX];

void go(int start) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ 0, start }); dist[start].push(0);
    while (!pq.empty()) {
        int cur_pos = pq.top().second;
        long long cur_dist = pq.top().first;
        pq.pop();

        for (auto next : edges[cur_pos]) {
            int next_pos = next.first;
            long long next_dist = next.second + cur_dist;
            if ((int)dist[next_pos].size() < k) {
                dist[next_pos].push(next_dist);
                pq.push({ next_dist, next_pos });
            }
            else if (dist[next_pos].top() > next_dist) {
                    dist[next_pos].pop();
                    dist[next_pos].push(next_dist);
                    pq.push({ next_dist, next_pos });
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b; long long c;
        scanf("%d %d %lld", &a, &b, &c);
        edges[a].push_back({b, c});
    }
    go(1);

    for (int i = 1; i <= n; i++) {
        if ((int)dist[i].size() >= k) {
            printf("%lld\n", dist[i].top());
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}