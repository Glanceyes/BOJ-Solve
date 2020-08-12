#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define V_MAX 802
#define WORK 400
#define SOURCE 0
#define SINK 801
#define INF 987654321

int n, m;
int max_work_num = 0;
int max_work_pay = 0;
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int pay[V_MAX][V_MAX];

vector<int> edges[V_MAX];

void MCMF() {
    while (1) {
        queue<int> q;
        int prv[V_MAX], dist[V_MAX];
        bool inQ[V_MAX];
        fill(prv, prv + V_MAX, -1);
        fill(dist, dist + V_MAX, INF);
        fill(inQ, inQ + V_MAX, false);
        dist[SOURCE] = 0;
        inQ[SOURCE] = true;
        q.push(SOURCE);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            inQ[cur] = false;

            for (int i = 0; i < (int)edges[cur].size(); i++) {
                int next = edges[cur][i];
                if (cap[cur][next] - flw[cur][next] > 0 &&
                    dist[next] > dist[cur] + pay[cur][next]) {
                    dist[next] = dist[cur] + pay[cur][next];
                    prv[next] = cur;
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
            max_work_pay += (-1) * min_flow * pay[prv[i]][i];
            flw[prv[i]][i] += min_flow;
            flw[i][prv[i]] -= min_flow;
        }
        max_work_num += min_flow;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int work_num; scanf("%d", &work_num);
        edges[SOURCE].push_back(i);
        edges[i].push_back(SOURCE);
        cap[SOURCE][i] = 1;
        for (int j = 0; j < work_num; j++) {
            int work_no, work_pay;
            scanf("%d %d", &work_no, &work_pay);
            work_no += WORK;
            edges[i].push_back(work_no);
            edges[work_no].push_back(i);
            cap[i][work_no] = 1;
            pay[i][work_no] = -work_pay;
            pay[work_no][i] = work_pay;
        }
    }
    for (int i = WORK + 1; i <= WORK + m; i++) {
        edges[i].push_back(SINK);
        edges[SINK].push_back(i);
        cap[i][SINK] = 1;
    }

    MCMF();
    printf("%d\n%d\n", max_work_num, max_work_pay);

    return 0;
}