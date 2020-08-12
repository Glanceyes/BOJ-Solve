#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 801
#define INF 987654321

int n, p, ans;
int prv[MAX];
int c[MAX][MAX]; 
int f[MAX][MAX];
vector<int> edge[MAX];

void MaxFlow(int start, int end) {
    while (1) {
        memset(prv, -1, sizeof(prv));
        queue<int> q; q.push(start); prv[start] = start;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == end) break;
            for (int i = 0; i < (int)edge[x].size(); i++) {
                int y = edge[x][i];
                if (c[x][y] - f[x][y] > 0 && prv[y] == -1) {
                    prv[y] = x; q.push(y);
                }
            }
        }
        if (prv[end] == -1) break;
        int minFlow = INF;
        for (int i = end; i != start; i = prv[i]) {
            minFlow = min(minFlow, c[prv[i]][i] - f[prv[i]][i]);
        }
        for (int i = end; i != start; i = prv[i]) {
            c[prv[i]][i] += minFlow;
            c[i][prv[i]] -= minFlow;
        }
        ans += minFlow;
    }
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        c[2 * i - 1][2 * i] = 1;
        edge[2 * i - 1].push_back(2 * i);
        edge[2 * i].push_back(2 * i - 1);
    }
    for (int i = 1; i <= p; i++) {
        int u, v; scanf("%d %d", &u, &v);
        c[2 * u][2 * v - 1] = 1;
        c[2 * v][2 * u - 1] = 1;
        edge[2 * u].push_back(2 * v - 1);
        edge[2 * v].push_back(2 * u - 1);
        edge[2 * v - 1].push_back(2 * u);
        edge[2 * u - 1].push_back(2 * v);
    }

    MaxFlow(2, 3);
    printf("%d\n", ans);

    return 0;
}