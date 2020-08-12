#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
using edge = pair<int, int>;
using EDGE = tuple<int, int, int, int>;

#define START 1
#define N_MAX 1001
#define INF 987654321

int n, m;
int dist1[N_MAX];
int dist2[N_MAX];
bool visited[N_MAX];

vector<edge> edges[N_MAX];
vector<edge> result;

void dijkstra(int start) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    for (int i = 1; i <= n; i++) {
        dist1[i] = INF;
    }

    pq.push({ 0, start }); dist1[start] = 0;
    while (!pq.empty()) {
        int cur_pos = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        if (dist1[cur_pos] < cur_dist) continue;

        for (auto next : edges[cur_pos]) {
            int next_pos = next.first;
            int next_dist = next.second + cur_dist;
            if (dist1[next_pos] > next_dist) {
                dist1[next_pos] = next_dist;
                pq.push({ next_dist, next_pos });
            }
        }
    }
}

bool prim_and_dijkstra(int start) {
    priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist2[i] = INF;
    }

    pq.push({ 0, 0, start, start}); 
    dist2[start] = 0;

    for (int i = 1; i <= n; i++) {
        int cur_pos = 0, cur_dist = INF, min_weight = INF;
        while (!pq.empty()) {
            int x, y, z, w; tie(x, y, z, w) = pq.top();
            pq.pop();
            if (!visited[z]) {
                if (z != w) {
                    result.push_back({ z, w });
                }
                cur_pos = z; cur_dist = y;
                min_weight = x; break;
            }
        }

        if (!cur_pos) return false;
        visited[cur_pos] = true;

        for (auto next : edges[cur_pos]) {
            int next_pos = next.first;
            int next_weight = next.second;
            int next_dist = next_weight + cur_dist;
            dist2[next_pos] = min(dist2[next_pos], next_dist);
            if (!visited[next_pos]) {
                if (dist2[next_pos] >= next_dist && next_dist <= dist1[next_pos]) {
                    dist2[next_pos] = next_dist;
                    pq.push({ next_weight, next_dist, next_pos, cur_pos });
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }

    dijkstra(START);
    prim_and_dijkstra(START);

    printf("%d\n", (int)result.size());
    for (auto x : result) {
        printf("%d %d\n", x.first, x.second);
    }

    return 0;
}