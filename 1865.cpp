#include <cstdio>
#include <vector>
#define INF 987654321
using namespace std;
using Edge = pair<int, int>;

bool isNegCycle(int* dist, vector<Edge> (&edge)[501], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < (int)edge[j].size(); k++) {
                int cur_pos = edge[j][k].first;
                int cur_cst = edge[j][k].second;
                if (dist[cur_pos] > dist[j] + cur_cst) {
                    dist[cur_pos] = dist[j] + cur_cst;
                    if (i == n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int dist[501];
        vector<Edge> edge[501];
        int n, m, w; scanf("%d %d %d", &n, &m, &w);
        for (int i = 0; i < m; i++) {
            int s, e, t; scanf("%d %d %d", &s, &e, &t);
            edge[s].push_back({ e, t });
            edge[e].push_back({ s, t });
        }
        for (int i = 0; i < w; i++) {
            int s, e, t; scanf("%d %d %d", &s, &e, &t);
            edge[s].push_back({ e, -t });
        }
        dist[1] = 0;
        for (int i = 2; i <= n; i++) {
            dist[i] = INF;
        }
        ((isNegCycle(dist, edge, n)) ? (printf("YES\n")) : (printf("NO\n")));
    }

    return 0;
}