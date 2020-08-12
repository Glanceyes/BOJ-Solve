#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 402
#define INF 1
using namespace std;

int n, m, s, e, ans;
int p[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
vector<int> edges[MAX];

void MaxFlow() {
    while (1) {
        memset(p, -1, sizeof(p));
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == e) break;
            for (int i = 0; i < (int)edges[x].size(); i++) {
                int y = edges[x][i];
                if (c[x][y] - f[x][y] > 0 && p[y] == -1) {
                    p[y] = x; q.push(y);
                }
            }
        }
        if (p[e] == -1) break;
        int minFlow = INF;
        for (int i = e; i != s; i = p[i]) {
            minFlow = min(minFlow, c[p[i]][i] - f[p[i]][i]);
        }
        for (int i = e; i != s; i = p[i]) {
            f[p[i]][i] += minFlow;
            f[i][p[i]] -= minFlow;
        }
        ans += minFlow;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    s = 0; e = n + m + 1;
    for (int i = 1; i <= n; i++) {
        int num; scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            int v; scanf("%d", &v);
            c[i][n + v] = 1;
            edges[i].push_back(n + v);
            edges[n + v].push_back(i);
        }
        c[s][i] = 1;
        edges[s].push_back(i);
        edges[i].push_back(s);
    }
    for (int i = 1; i <= m; i++) {
        c[n + i][e] = 1;
        edges[n + i].push_back(e);
        edges[e].push_back(n + i);
    }
    MaxFlow();
    printf("%d\n", ans);

    return 0;
}