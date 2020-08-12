#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 202
#define SOURCE 0
#define SINK 201
#define QUESTION 100
#define INF 987654321

int n;
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int cst[V_MAX][V_MAX];

vector<int> edges[V_MAX];

int MCMF() {
    int result = 0;
    while (1) {
        queue<int> q;
        int prv[V_MAX], dst[V_MAX];
        bool inQ[V_MAX];
        fill(prv, prv + V_MAX, -1);
        fill(dst, dst + V_MAX, INF);
        fill(inQ, inQ + V_MAX, false);

        inQ[SOURCE] = true;
        dst[SOURCE] = 0;
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        edges[SOURCE].push_back(i);
        edges[i].push_back(SOURCE);
        cap[SOURCE][i] = 1;
        for (int j = QUESTION + 1; j <= QUESTION + n; j++) {
            edges[i].push_back(j);
            edges[j].push_back(i);
            cap[i][j] = 1;
            int cost; scanf("%d", &cost);
            cst[i][j] = cost;
            cst[j][i] = -cost;
        }
    }

    for (int i = QUESTION + 1; i <= QUESTION + n; i++) {
        edges[i].push_back(SINK);
        edges[SINK].push_back(i);
        cap[i][SINK] = 1;
    }

    printf("%d\n", MCMF());
}