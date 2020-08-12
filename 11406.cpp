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

vector<int> edges[202];

int MaxFlow() {
    int result = 0;
    while (1) {
        queue<int> q;
        int prv[V_MAX];
        fill(prv, prv + V_MAX, -1);
        q.push(SOURCE);
        while (!q.empty() && prv[SINK] == -1) {
            int cur = q.front(); q.pop();
            if (cur == SINK) break;

            for (int i = 0; i < (int)edges[cur].size(); i++) {
                int next = edges[cur][i];
                if (cap[cur][next] - flw[cur][next] > 0 && prv[next] == -1) {
                    prv[next] = cur; q.push(next);
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
            edges[i].push_back(j);
            edges[j].push_back(i);
        }
    }

    printf("%d\n", MaxFlow());

    return 0;
}