#include <cstdio>
#include <vector>
using namespace std;

#define N_MAX 100001
#define D_MAX 19

int n, m;
int d[N_MAX][D_MAX];
int s[N_MAX];

vector<pair<int, int>> edges[N_MAX];

int depth[N_MAX];
bool visited[N_MAX];

void swap(int& x, int& y) {
    int temp = x;
    x = y; y = temp;
}

void dfs(int here, int dph, int dst) {
    visited[here] = true;
    depth[here] = dph;
    for (auto next : edges[here]) {
        if (!visited[next.first]) {
            d[next.first][0] = here;
            s[next.first] = dst + next.second;
            dfs(next.first, dph + 1, s[next.first]);
        }
    }
}

int main() {
    scanf("%d", &n);
    fill(d[0], d[0] + N_MAX * D_MAX, -1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        edges[a].push_back({ b, 1 });
        edges[b].push_back({ a, 1 });
    }
    s[1] = 0;
    dfs(1, 0, 0);

    for (int j = 1; j < D_MAX; j++) {
        for (int i = 1; i <= n; i++) {
            if (d[i][j - 1] != -1) {
                d[i][j] = d[d[i][j - 1]][j - 1];
            }
        }
    }

    int m; scanf("%d", &m);
    int a, b, ans = 0; scanf("%d", &a);
    for (int i = 1; i < m; i++) {
        int temp_a = 0; scanf("%d", &b);
        temp_a = b;
        ans += s[a] + s[b];
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 0; i < D_MAX && diff; i++, diff /= 2) {
            if (diff % 2) a = d[a][i];
        }
        if (a != b) {
            for (int i = D_MAX - 1; i >= 0; i--) {
                if (d[a][i] != -1 && d[a][i] != d[b][i]) {
                    a = d[a][i]; b = d[b][i];
                }
            }
            a = d[a][0];
        }
        ans -= s[a] * 2;
        a = temp_a;
    }
    printf("%d\n", ans);

    return 0;
}