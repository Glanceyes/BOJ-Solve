#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 1002
#define SOURCE 0
#define SINK 1001
#define OUT 500
#define INF 987654321

int n, m;
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int prv[V_MAX];
vector<int> edges[V_MAX];

int maxFlow() {
    int result = 0;
    while (1) {
        queue<int> q; q.push(SOURCE);
        fill(prv, prv + V_MAX, -1);
        while (!q.empty() && prv[SINK] == -1) {
            int here = q.front(); q.pop();
            for (auto next : edges[here]) {
                if (cap[here][next] - flw[here][next] > 0 && prv[next] == -1) {
                    prv[next] = here; q.push(next);
                }
            }
        }
        if (prv[SINK] == -1) break;
        int min_flow = INF;
        for (int i = SINK; i != SOURCE; i = prv[i]) {
            min_flow = min(min_flow, cap[prv[i]][i] - flw[prv[i]][i]);
        }
        for (int i = SINK; i != SOURCE; i = prv[i]) {
            flw[prv[i]][i] += min_flow;
            flw[i][prv[i]] -= min_flow;
        }
        result += min_flow;
    }
    return result;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        edges[i].push_back(i + OUT);
        edges[i + OUT].push_back(i);
        cap[i][i + OUT] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges[a + OUT].push_back(b);
        edges[b].push_back(a + OUT);
        cap[a + OUT][b] = c;

        edges[b + OUT].push_back(a);
        edges[a].push_back(b + OUT);
        cap[b + OUT][a] = c;
    }
    int s, t; scanf("%d %d", &s, &t);
    edges[SOURCE].push_back(s);
    edges[s].push_back(SOURCE);
    cap[SOURCE][s] = INF;
    edges[t + OUT].push_back(SINK);
    edges[SINK].push_back(t + OUT);
    cap[t + OUT][SINK] = INF;

    printf("%d\n", maxFlow());
    return 0;
}