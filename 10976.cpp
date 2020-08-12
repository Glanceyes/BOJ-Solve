#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 201
#define INF 0x3f3f3f3f

int t, n, m;
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int prv[V_MAX];
int maxFlow(int source, int sink, vector<vector<int>>& edges) {
    int result = 0;
    while (1) {
        queue<int> q;
        fill(prv, prv + V_MAX, -1);
        q.push(source);
        while (!q.empty() && prv[sink] == -1) {
            int here = q.front(); q.pop();
            for (auto next : edges[here]) {
                if (cap[here][next] - flw[here][next] > 0 && prv[next] == -1) {
                    prv[next] = here; q.push(next);
                }
            }
        }
        if (prv[sink] == -1) break;
        int min_flow = INF;
        for (int i = sink; i != source; i = prv[i]) {
            min_flow = min(min_flow, cap[prv[i]][i] - flw[prv[i]][i]);
        }
        for (int i = sink; i != source; i = prv[i]) {
            flw[prv[i]][i] += min_flow;
            flw[i][prv[i]] -= min_flow;
        }
        result += min_flow;
    }
    return result;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        vector<vector<int>> edges(n + 1);
        fill(cap[0], cap[0] + V_MAX * V_MAX, 0);
        fill(flw[0], flw[0] + V_MAX * V_MAX, 0);
        for (int i = 0; i < m; i++) {
            int x, y; scanf("%d %d", &x, &y);
            edges[x].push_back(y);
            edges[y].push_back(x);
            if (x == 1 || y == 1 || x == n || y == n) {
                cap[x][y] = 1;
            }
            else {
                cap[x][y] = INF;
            }
        }
        printf("%d\n", maxFlow(1, n, edges));
    }

    return 0;
}