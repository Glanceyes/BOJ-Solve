#include <cstdio>
#include <vector>
using namespace std;

#define V_MAX 3200

typedef vector<vector<bool>> matrix_bool;
typedef vector<vector<int>> matrix_int;

int c, n, m;
int select_a[V_MAX];
int select_b[V_MAX];
bool visited[V_MAX];
vector<int> edges[V_MAX];

int dx[6] = { -1, 0, 1, -1, 0, 1 };
int dy[6] = { -1, -1, -1, 1, 1, 1 };

bool bipartite_match(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (auto b : edges[a]) {
        if (select_b[b] == -1 || bipartite_match(select_b[b])) {
            select_a[a] = b; select_b[b] = a; return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &c);
    while (c--) {
        scanf("%d %d", &n, &m); getchar();
        matrix_bool mat(n, vector<bool>(m));
        matrix_int vertex(n, vector<int>(m));

        fill(select_a, select_a + V_MAX, -1);
        fill(select_b, select_b + V_MAX, -1);

        for (int i = 0; i < V_MAX; i++) {
            edges[i].clear();
        }

        int cnt_x = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char val = getchar();
                if (val == 'x') {
                    mat[i][j] = false; cnt_x++;
                }
                else {
                    mat[i][j] = true;
                }
            }
            getchar();
        }
        int cnt_a = 0, cnt_b = 0;
        for (int j = 0; j < m; j += 2) {
            for (int i = 0; i < n; i++) {
                vertex[i][j] = cnt_a;
                cnt_a += 1;
            }
        }

        for (int j = 1; j < m; j += 2) {
            for (int i = 0; i < n; i++) {
                vertex[i][j] = cnt_b;
                cnt_b += 1;
            }
        }

        for (int j = 0; j < m; j += 2) {
            for (int i = 0; i < n; i++) {
                if (!mat[i][j]) continue;
                for (int k = 0; k < 6; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny]) {
                        int idx_a = vertex[i][j];
                        int idx_b = vertex[nx][ny];
                        edges[idx_a].push_back(idx_b);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < cnt_a; i++) {
            fill(visited, visited + V_MAX, false);
            if (bipartite_match(i)) cnt++;
        }
        printf("%d\n", n * m - cnt_x - cnt);
    }

    return 0;
}