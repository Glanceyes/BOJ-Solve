#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define BOOK 100
#define SOURCE 0
#define SINK 201
#define V_MAX 202
#define INF 987654321

int n, m;
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int cost[V_MAX][V_MAX];

vector<int> edges[202];

void MCMF(int &result1, int &result2) {
    result2 = 0;
    while (1) {
        queue<int> q;
        int prv[V_MAX], dist[V_MAX];
        bool exist[V_MAX];
        fill(prv, prv + V_MAX, -1);
        fill(dist, dist + V_MAX, INF);
        fill(exist, exist + V_MAX, false);
        dist[SOURCE] = 0;
        exist[SOURCE] = true;
        q.push(SOURCE);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            exist[cur] = false;

            for (int i = 0; i < (int)edges[cur].size(); i++) {
                int next = edges[cur][i];
                if (cap[cur][next] - flw[cur][next] > 0 &&
                    dist[next] > dist[cur] + cost[cur][next]) {
                    dist[next] = dist[cur] + cost[cur][next];
                    prv[next] = cur;
                    if (!exist[next]) {
                        exist[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        if (prv[SINK] == -1) break;
        int min_flow = INF;
        for (int i = SINK; i != SOURCE; i = prv[i]) {
            min_flow = min(min_flow, cap[prv[i]][i] - flw[prv[i]][i]);
        }
        for (int i = SINK; i != SOURCE; i = prv[i]) {
            result2 += min_flow * cost[prv[i]][i];
            flw[prv[i]][i] += min_flow;
            flw[i][prv[i]] -= min_flow;
        }
        result1 += min_flow;
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cap[i + BOOK][SINK]);
        edges[i + BOOK].push_back(SINK);
        edges[SINK].push_back(i + BOOK);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &cap[SOURCE][i]);
        edges[SOURCE].push_back(i);
        edges[i].push_back(SOURCE);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = BOOK + 1; j <= BOOK + n; j++) {
            scanf("%d", &cap[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = BOOK + 1; j <= BOOK + n; j++) {
            edges[i].push_back(j);
            edges[j].push_back(i);
            int val; scanf("%d", &val);
            cost[i][j] = val;
            cost[j][i] = -val;
        }
    }

    int max_book = 0, min_shipment = 0;
    MCMF(max_book, min_shipment);
    printf("%d\n%d\n", max_book, min_shipment);

    return 0;
}