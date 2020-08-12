#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using line = pair<long long, int>;
using pqline = tuple<long long, int, int>;

#define MAX_VALUE 50000000000

int n, m, k;
long long cost[10001][21];
vector<line> road[10001];

void find() {
    priority_queue<pqline, vector<pqline>, greater<pqline>> pq;
    pq.push({ 0, 1, 0 }); cost[1][0] = 0;

    while (!pq.empty()) {
        long long cur_cost; int cur_pos, cur_denum;
        tie(cur_cost, cur_pos, cur_denum) = pq.top(); pq.pop();
       
        if (cost[cur_pos][cur_denum] < cur_cost) continue;

        for (int i = 0; i < (int)road[cur_pos].size(); i++) {
            int neigh_pos = road[cur_pos][i].second;
            long long neigh_cost = cur_cost + road[cur_pos][i].first;

            if (cost[neigh_pos][cur_denum] > neigh_cost) {
                cost[neigh_pos][cur_denum] = neigh_cost;
                pq.push({ neigh_cost, neigh_pos, cur_denum });
            }

            if (cur_denum + 1 <= k) {
                if (cost[neigh_pos][cur_denum + 1] > cur_cost) {
                    cost[neigh_pos][cur_denum + 1] = cur_cost;
                    pq.push({ cur_cost, neigh_pos, cur_denum + 1 });
                }
            }
        }

    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cost[i][j] = MAX_VALUE;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b; long long c;
        scanf("%d %d %lld", &a, &b, &c);
        road[a].push_back({ c, b });
        road[b].push_back({ c, a });
    }

    find(); long long ans = MAX_VALUE;
    for (int i = 0; i <= k; i++) {
        if (cost[n][i] < ans) {
            ans = cost[n][i];
        }
    }
    printf("%lld\n", ans);

    return 0;
}