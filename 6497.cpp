#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using road = pair<long long, int>;

#define M_MAX 200000
#define INF 3000000000

int m, n;
long long sum;
bool selected[M_MAX];
vector<road> roads[M_MAX];

long long prim() {
    long long result = 0;
    for (int i = 0; i < m; i++) {
        selected[i] = false;
    }
    priority_queue<road, vector<road>, greater<road>> dist;
    dist.push({ 0, 0 });
    for (int i = 0; i < m; i++) {
        int cur_pos = -1; long long min_dist = INF;
        while (!dist.empty()) {
            cur_pos = dist.top().second; 
            long long cur_dist = dist.top().first;
            dist.pop();
            if (!selected[cur_pos] && min_dist > cur_dist) {
                min_dist = cur_dist; break;
            }
        }
        if (min_dist == INF) return INF;
        result += min_dist;
        selected[cur_pos] = true;
        for (auto next : roads[cur_pos]) {
            dist.push({ next.first, next.second });
        }
    }
    return result;
}

int main() {
    while (1) {
        sum = 0;
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        for (int i = 0; i < m; i++) {
            roads[i].clear();
        }
        for (int i = 0; i < n; i++) {
            int x, y; long long z;
            scanf("%d %d %lld", &x, &y, &z);
            roads[x].push_back({ z, y });
            roads[y].push_back({ z, x });
            sum += z;
        }
        printf("%lld\n", sum - prim());
    }

    return 0;
}