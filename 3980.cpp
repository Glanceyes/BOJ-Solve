#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define NUM 24
#define POS 11
#define SOURCE 0
#define SINK 23
#define INF 0x3f3f3f3f

int main() {
    int c; scanf("%d", &c);
    while (c--) {
        int cap[NUM][NUM];
        int flw[NUM][NUM];
        int cst[NUM][NUM];
        fill(cap[0], cap[0] + NUM * NUM, 0);
        fill(flw[0], flw[0] + NUM * NUM, 0);
        fill(cst[0], cst[0] + NUM * NUM, 0);
        vector<int> edges[NUM];
        for (int i = 1; i <= 11; i++) {
            edges[SOURCE].push_back(i);
            edges[i].push_back(SOURCE);
            cap[SOURCE][i] = 1;
            for (int j = POS + 1; j <= POS + 11; j++) {
                int val; scanf("%d", &val);
                if (!val) continue;
                edges[i].push_back(j);
                edges[j].push_back(i);
                cap[i][j] = 1;
                cst[i][j] = -val;
                cst[j][i] = val;
            }
        }
        for (int i = POS + 1; i <= POS + 11; i++) {
            edges[i].push_back(SINK);
            edges[SINK].push_back(i);
            cap[i][SINK] = 1;
        }

        int ans = 0;
        while (1) {
            queue<int> q;
            int prv[NUM], dst[NUM];
            bool inQ[NUM];
            fill(prv, prv + NUM, -1);
            fill(dst, dst + NUM, INF);
            fill(inQ, inQ + NUM, false);
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
                ans += (cap[prv[i]][i] - flw[prv[i]][i]) * cst[prv[i]][i];
                flw[prv[i]][i] += min_flow;
                flw[i][prv[i]] -= min_flow;
            }
        }
        printf("%d\n", -ans);
    }

    return 0;
}