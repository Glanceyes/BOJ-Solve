#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N_MAX 52
#define M_MAX 52
#define V_MAX 2502
#define V_START 0
#define V_END 2501
#define INF 987654321

int t, n, m;
int mat[N_MAX][M_MAX];
int cap[V_MAX][V_MAX];
int flw[V_MAX][V_MAX];
int prv[V_MAX];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<int> edges[V_MAX];

int maxFlow() {
    int result = 0;
    while (1) {
        fill(prv, prv + V_MAX, -1);
        queue<int> q; q.push(V_START);
        while (!q.empty() && prv[V_END] == -1) {
            int x = q.front(); q.pop();
            if (x == V_END) break;
            for (auto nx : edges[x]) {
                if (cap[x][nx] - flw[x][nx] > 0 && prv[nx] == -1) {
                    prv[nx] = x; q.push(nx);
                    if (nx == V_END) break;
                }
            }
        }
        if (prv[V_END] == -1) break;
        int minFlow = INF;
        for (int i = V_END; i != V_START; i = prv[i]) {
            minFlow = min(minFlow, cap[prv[i]][i] - flw[prv[i]][i]);
        }
        for (int i = V_END; i != V_START; i = prv[i]) {
            flw[prv[i]][i] += minFlow;
            flw[i][prv[i]] -= minFlow;
        }
        result += minFlow;
    }
    return result;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        
        for (int i = 0; i < V_MAX; i++) {
            for (int j = 0; j < V_MAX; j++) {
                cap[i][j] = flw[i][j] = 0;
            }
            edges[i].clear();
        }

        int sum = 0, idx_a = 1, idx_b = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val; scanf("%d", &val);
                if ((i + j) % 2 == 0) {
                    edges[V_START].push_back(idx_a);
                    edges[idx_a].push_back(V_START);
                    cap[V_START][idx_a] = val;
                    mat[i][j] = idx_a; idx_a += 2;
                }
                else {
                    edges[idx_b].push_back(V_END);
                    edges[V_END].push_back(idx_b);
                    cap[idx_b][V_END] = val;
                    mat[i][j] = idx_b; idx_b += 2;
                }
                sum += val;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    int x_a = i, y_a = j;
                    for (int k = 0; k < 4; k++) {
                        int x_b = x_a + dx[k];
                        int y_b = y_a + dy[k];
                        if (x_b >= 0 && x_b < n && y_b >= 0 && y_b < m) {
                            idx_a = mat[x_a][y_a];
                            idx_b = mat[x_b][y_b];
                            edges[idx_a].push_back(idx_b);
                            edges[idx_b].push_back(idx_a);
                            cap[idx_a][idx_b] = INF;
                        }
                    }
                }
            }
        }
        printf("%d\n", sum - maxFlow());
        
    }

    return 0;
}