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

int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int cst[V_MAX][V_MAX];
int prv[V_MAX], dst[V_MAX];
bool inQ[V_MAX];
vector<int> edges[V_MAX];

int MCMF() {
    int cnt = 2;
    int result = 0;
    while (cnt--) {
        queue<int> q;
        fill(prv, prv + V_MAX, -1);
        fill(dst, dst + V_MAX, INF);
        fill(inQ, inQ + V_MAX, false);

        dst[SOURCE] = 0;
        inQ[SOURCE] = true;
        q.push(SOURCE);
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
            flw[prv[i]][i] += min_flow;
            flw[i][prv[i]] -= min_flow;
        }
    }
    return result;
}



int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int v, e; scanf("%d %d", &v, &e);
        fill(cap[0], cap[0] + V_MAX * V_MAX, 0);
        fill(flw[0], flw[0] + V_MAX * V_MAX, 0);
        fill(cst[0], cst[0] + V_MAX * V_MAX, 0);
        for (int i = 1; i < V_MAX; i++) {
            edges[i].clear();
        }

        for (int i = 1; i <= v; i++) {
            edges[i].push_back(i + OUT);
            edges[i + OUT].push_back(i);
            cap[i][i + OUT] = 1;
            cst[i][i + OUT] = -1;
            cst[i + OUT][i] = 1;

            edges[SOURCE].push_back(i);
            edges[i].push_back(SOURCE);
            cap[SOURCE][i] = 1;

            edges[i + OUT].push_back(SINK);
            edges[SINK].push_back(i + OUT);
            cap[i + OUT][SINK] = 1;
        }

        for (int i = 1; i <= e; i++) {
            int a, b; scanf("%d %d", &a, &b);
            edges[a + OUT].push_back(b);
            edges[b].push_back(a + OUT);
            cap[a + OUT][b] = INF;
        }
        printf("%d\n", (-1) * MCMF());
    }

    return 0;
}