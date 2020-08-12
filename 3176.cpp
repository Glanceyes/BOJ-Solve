#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 100001
#define D_MAX 19
#define INF 0x3f3f3f3f

int n, m;
int d[N_MAX][D_MAX];
int min_e[N_MAX][D_MAX];
int max_e[N_MAX][D_MAX];

vector<pair<int, int>> edges[N_MAX];

int depth[N_MAX];
bool visited[N_MAX];

void swap(int& x, int& y) {
    int temp = x;
    x = y; y = temp;
}

void dfs(int here, int dph) {
    visited[here] = true;
    depth[here] = dph;

    for (auto next : edges[here]) {
        if (!visited[next.first]) {
            d[next.first][0] = here;
            min_e[next.first][0] = next.second;
            max_e[next.first][0] = next.second;
            dfs(next.first, dph + 1);
        }
    }
}



int main() {
    scanf("%d", &n);
    fill(d[0], d[0] + N_MAX * D_MAX, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }
    dfs(1, 0);

    for (int j = 1; j < D_MAX; j++) {
        for (int i = 1; i <= n; i++) {
            int temp = d[i][j - 1];
            if (temp != -1) {
                d[i][j] = d[temp][j - 1];
                min_e[i][j] = min(min_e[i][j - 1], min_e[temp][j - 1]);
                max_e[i][j] = max(max_e[i][j - 1], max_e[temp][j - 1]);
            }
        }
    }

    for (int j = 1; j < D_MAX; j++) {
        for (int i = 1; i <= n; i++) {
            int temp = d[i][j - 1];
            if (temp != -1) {
                min_e[i][j] = min(min_e[i][j - 1], min_e[temp][j - 1]);
                max_e[i][j] = max(max_e[i][j - 1], max_e[temp][j - 1]);
            }
        }
    }

    int m; scanf("%d", &m);

    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        int min_E = INF, max_E = 0;
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];

        for (int i = 0; i < D_MAX && diff; i++, diff /= 2) {
            if (diff % 2) {
                min_E = min(min_E, min_e[a][i]);
                max_E = max(max_E, max_e[a][i]);
                a = d[a][i];
            }
        }

        if (a != b) {
            for (int i = D_MAX - 1; i >= 0; i--) {
                if (d[a][i] != -1 && d[a][i] != d[b][i]) {
                    min_E = min(min_E, min(min_e[a][i], min_e[b][i]));
                    max_E = max(max_E, max(max_e[a][i], max_e[b][i]));
                    a = d[a][i]; b = d[b][i];
                }
            }
            min_E = min(min_E, min(min_e[a][0], min_e[b][0]));
            max_E = max(max_E, max(max_e[a][0], max_e[b][0]));
        }
        printf("%d %d\n", min_E, max_E);
        
    }

    return 0;
}