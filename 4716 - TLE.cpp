#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 1004
#define ROOM_A 1001
#define ROOM_B 1002
#define SOURCE 0
#define SINK 1003
#define INF 987654321

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
    while (1) {
        fill(cap[0], cap[0] + V_MAX * V_MAX, 0);
        fill(flw[0], flw[0] + V_MAX * V_MAX, 0);
        fill(cst[0], cst[0] + V_MAX * V_MAX, 0);
        int n, a, b; scanf("%d %d %d", &n, &a, &b);
        if (!n && !a && !b) break;
        edges[SOURCE].push_back(ROOM_A);
        edges[ROOM_A].push_back(SOURCE);
        cap[SOURCE][ROOM_A] = a;

        edges[SOURCE].push_back(ROOM_B);
        edges[ROOM_B].push_back(SOURCE);
        cap[SOURCE][ROOM_B] = b;
        for (int i = 1; i <= n; i++) {
            edges[ROOM_A].push_back(i);
            edges[i].push_back(ROOM_A);
            cap[ROOM_A][i] = INF;

            edges[ROOM_B].push_back(i);
            edges[i].push_back(ROOM_B);
            cap[ROOM_B][i] = INF;

            scanf("%d", &cap[i][SINK]);
            edges[i].push_back(SINK);
            edges[SINK].push_back(i);

            int da, db; scanf("%d %d", &da, &db);

            cst[ROOM_A][i] = da;
            cst[i][ROOM_A] = -da;
            cst[ROOM_B][i] = db;
            cst[i][ROOM_B] = -db;
        }
        printf("%d\n", MCMF());
    }

    return 0;

}