#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 52
#define INF 987654321

int n, ans;
int cap[MAX][MAX];
int flw[MAX][MAX];
int prv[MAX];
vector<int> edges[MAX];

int char_to_int(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    return 0;
}

void MaxFlow(int start, int end) {
    while (1) {
        memset(prv, -1, sizeof(prv));
        queue<int> q; q.push(start);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == end) break;
            for (int i = 0; i < (int)edges[x].size(); i++) {
                int y = edges[x][i];
                if (cap[x][y] - flw[x][y] > 0 && prv[y] == -1) {
                    q.push(y); prv[y] = x;
                }
            }
        }
        if (prv[end] == -1) break;

        int flow = INF;
        for (int i = end; i != start; i = prv[i]) {
            flow = min(flow, cap[prv[i]][i] - flw[prv[i]][i]);
        }
        for (int i = end; i != start; i = prv[i]) {
            flw[prv[i]][i] += flow;
            flw[i][prv[i]] -= flow;
        }
        ans += flow;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char u, v; int m, ui, vi;
        getchar();
        scanf("%c %c %d", &u, &v, &m);
        ui = char_to_int(u);
        vi = char_to_int(v);
        cap[ui][vi] += m;
        cap[vi][ui] += m;
        edges[ui].push_back(vi);
        edges[vi].push_back(ui);
    }

    MaxFlow(0, 25);
    printf("%d\n", ans);

    return 0;
}