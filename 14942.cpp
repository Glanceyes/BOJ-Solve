#include <cstdio>
#include <vector>
using namespace std;

#define N_MAX 100001
#define D_MAX 18

int n;
int ant[N_MAX];
int acs[N_MAX][D_MAX];
int dst[N_MAX][D_MAX];
bool visit[N_MAX];
vector<pair<int, int>> edges[N_MAX];

void dfs(int here) {
    visit[here] = true;

    for (auto next : edges[here]) {
        if (!visit[next.first]) {
            acs[next.first][0] = here;
            dst[next.first][0] = next.second;
            dfs(next.first);
        }
    }
}



int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &ant[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }
    dfs(1);

    acs[1][0] = 1;
    dst[1][0] = 0;
    for (int j = 1; j < D_MAX; j++) {
        for (int i = 1; i <= n; i++) {
            if (acs[i][j - 1]) {
                acs[i][j] = acs[acs[i][j - 1]][j - 1];
                dst[i][j] = dst[i][j - 1] + dst[acs[i][j - 1]][j - 1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int idx = i;
        for (int j = D_MAX - 1; j >= 0; j--) {
            if (ant[i] >= dst[idx][j]) {
                ant[i] -= dst[idx][j];
                idx = acs[idx][j];
           }
        }
        printf("%d\n", idx);
    }

    return 0;
}