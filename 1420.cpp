#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
using CDN = pair<int, int>;

#define N_MAX 101
#define M_MAX 101
#define E_MAX 20010
#define INF 0x3f3f3f3f

int n, m;
char city[N_MAX][M_MAX];
vector<int> edges[E_MAX];
map<CDN, int> cap;
map<CDN, int> flw;
int prv[E_MAX];

int absValue(int x, int y) {
    if (x < y) return (y - x);
    return (x - y);
}

int maxFlow(int source, int sink) {
    int result = 0;
    while (1) {
        fill(prv, prv + E_MAX, -1);
        queue<int> q; q.push(source);
        while (!q.empty() && prv[sink] == -1) {
            int here = q.front(); q.pop();
            for (auto next : edges[here]) {
                if (cap[{here, next}] - flw[{here, next}] > 0 && prv[next] == -1) {
                    prv[next] = here; q.push(next);
                }
            }
        }
        if (prv[sink] == -1) break;
        int min_flow = INF;
        for (int i = sink; i != source; i = prv[i]) {
            min_flow = min(min_flow, cap[{prv[i], i}] - flw[{prv[i], i}]);
        }
        for (int i = sink; i != source; i = prv[i]) {
            flw[{prv[i], i}] += min_flow;
            flw[{i, prv[i]}] -= min_flow;
        }
        result += min_flow;
    }
    return result;
}

int main() {
    scanf("%d %d", &n, &m); getchar();
    if (n == 1 && m == 1) {
        printf("-1\n"); return 0;
    }
    int source = 0, sink = 0;
    CDN SOURCE = { 0, 0 }, SINK = { 0, 0 };
    for (int i = 1, cnt = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            city[i][j] = getchar();
            switch (city[i][j]) {
            case 'K':
                source = cnt + 1; 
                SOURCE = { i, j }; 
                break;
            case 'H':
                sink = cnt; 
                SINK = { i, j };
                break;
            }
            cnt += 2;
        }
        getchar();
    }
    if (absValue(SOURCE.first, SINK.first) + absValue(SOURCE.second, SINK.second) == 1) {
        printf("-1\n"); return 0;
    }
    if (!source || !sink) {
        printf("-1\n"); return 0;
    }
    for (int i = 1; i <= n * m; i++) {
        edges[2 * i - 1].push_back(2 * i);
        edges[2 * i].push_back(2 * i - 1);
        cap[{2 * i - 1, 2 * i}] = 1;
        cap[{2 * i, 2 * i - 1}] = 0;
    }
    
    int here = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j + 1 <= m && city[i][j] != '#' && city[i][j + 1] != '#') {
                int next = here + 2;
                edges[here + 1].push_back(next);
                edges[next].push_back(here + 1);
                cap[{here + 1, next}] = INF;
                cap[{next, here + 1}] = 0;

                edges[next + 1].push_back(here);
                edges[here].push_back(next + 1);
                cap[{next + 1, here}] = INF;
                cap[{here, next + 1}] = 0;
            }
            if (i + 1 <= n && city[i][j] != '#' && city[i + 1][j] != '#') {
                int next = here + 2 * m;
                edges[here + 1].push_back(next);
                edges[next].push_back(here + 1);
                cap[{here + 1, next}] = INF;
                cap[{next, here + 1}] = 0;

                edges[next + 1].push_back(here);
                edges[here].push_back(next + 1);
                cap[{next + 1, here}] = INF;
                cap[{here, next + 1}] = 0;
            }
            here += 2;
        }
    }
    printf("%d\n", maxFlow(source, sink));

    return 0;
}