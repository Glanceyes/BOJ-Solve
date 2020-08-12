#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 401
#define INF 1
#define START 1
#define END 2

using namespace std;

int n, p, ans;
int d[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
vector<int> edges[MAX];

void MaxFlow() {
    while (1) {
        memset(d, -1, sizeof(d));
        queue<int> q; q.push(START);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == END) break;
            for (int i = 0; i < (int)edges[x].size(); i++) {
                int y = edges[x][i];
                if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    d[y] = x; q.push(y);
                }
            }
        }
        if (d[END] == -1) break;
        int vacancy = INF;
        for (int i = END; i != START; i = d[i]) {
            vacancy = min(vacancy, c[d[i]][i] - f[d[i]][i]);
        }
        for (int i = END; i != START; i = d[i]) {
            f[d[i]][i] += vacancy;
            f[i][d[i]] -= vacancy;
        }
        ans += vacancy;
    }
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < p; i++) {
        int u, v; scanf("%d %d", &u, &v);
        c[u][v] = 1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    MaxFlow();
    printf("%d\n", ans);

    return 0;
}