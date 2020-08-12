#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 602
#define SOURCE 0
#define SINK 601
#define OUT 300
#define INF 987654321

int n, m;
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int cst[V_MAX][V_MAX];
int prv[V_MAX];
int dst[V_MAX];
bool inQ[V_MAX];

int maxFlow(vector<vector<int>>& edges) {
    int result = 0;
    while (1) {
        queue<int> q;
        fill(prv, prv + V_MAX, -1);
        fill(dst, dst + V_MAX, INF);
        fill(inQ, inQ + V_MAX, false);
        q.push(SOURCE); dst[SOURCE] = 0;
        inQ[SOURCE] = true;
        while (!q.empty()) {
            int here = q.front(); q.pop();
            inQ[here] = false;
            for (auto next : edges[here]) {
                if (cap[here][next] - flw[here][next] > 0 &&
                    dst[next] > dst[here] + cst[here][next]) {
                    dst[next] = dst[here] + cst[here][next];
                    prv[next] = here;
                    if (!inQ[next]) {
                        inQ[next] = true;
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
            result += min_flow * cst[prv[i]][i];
            flw[prv[i]][i] += 1;
            flw[i][prv[i]] -= 1;
        }
    }
    return result;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        fill(cap[0], cap[0] + V_MAX * V_MAX, 0);
        fill(flw[0], flw[0] + V_MAX * V_MAX, 0);
        fill(cst[0], cst[0] + V_MAX * V_MAX, 0);
        vector<vector<int>> edges(V_MAX);
        for (int i = 1; i <= n; i++) {
            edges[i].push_back(i + OUT);
            edges[i + OUT].push_back(i);
            cap[i][i + OUT] = 1;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            edges[a + OUT].push_back(b);
            edges[b].push_back(a + OUT);
            cap[a + OUT][b] = INF;
            cst[a + OUT][b] = 1;
            cst[b][a + OUT] = -1;
        }
        edges[SOURCE].push_back(2);
        edges[2].push_back(SOURCE);
        cap[SOURCE][2] = 2;
        edges[1 + OUT].push_back(SINK);
        edges[SINK].push_back(1 + OUT);
        cap[1 + OUT][SINK] = INF;
        edges[n + OUT].push_back(SINK);
        edges[SINK].push_back(n + OUT);
        cap[n + OUT][SINK] = INF;

        printf("%d\n", maxFlow(edges));
    }
    return 0;
}