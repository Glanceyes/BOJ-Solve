#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 2001
#define OUT 1000
#define INF 987654321

int SOURCE, SINK;
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

        if (prv[SINK + OUT] == -1) break;
        int min_flow = INF;
        for (int i = SINK + OUT; i != SOURCE; i = prv[i]) {
            min_flow = min(min_flow, cap[prv[i]][i] - flw[prv[i]][i]);
        }
        for (int i = SINK + OUT; i != SOURCE; i = prv[i]) {
            result += min_flow * cst[prv[i]][i];
            flw[prv[i]][i] += min_flow;
            flw[i][prv[i]] -= min_flow;
        }
    }
    return result;
}



int main() {
    int v, e;
    while (scanf("%d %d", &v, &e) != EOF) {
        SOURCE = 1; SINK = v;
        fill(cap[0], cap[0] + V_MAX * V_MAX, 0);
        fill(flw[0], flw[0] + V_MAX * V_MAX, 0);
        fill(cst[0], cst[0] + V_MAX * V_MAX, 0);
        for (int i = 1; i < V_MAX; i++) {
            edges[i].clear();
        }

        edges[SOURCE].push_back(SOURCE + OUT);
        edges[SOURCE + OUT].push_back(SOURCE);
        cap[SOURCE][SOURCE + OUT] = 2;
        edges[SINK].push_back(SINK + OUT);
        edges[SINK + OUT].push_back(SINK);
        cap[SINK][SINK + OUT] = 2;

        for (int i = 2; i < v; i++) {
            edges[i].push_back(i + OUT);
            edges[i + OUT].push_back(i);
            cap[i][i + OUT] = 1;
        }

        for (int i = 1; i <= e; i++) {
            int a, b, c; scanf("%d %d %d", &a, &b, &c);
            edges[a + OUT].push_back(b);
            edges[b].push_back(a + OUT);
            cst[a + OUT][b] = c;
            cst[b][a + OUT] = -c;
            cap[a + OUT][b] = 1;
        }
        printf("%d\n", MCMF());
    }

    return 0;
}