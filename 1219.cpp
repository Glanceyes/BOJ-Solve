#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
#define INF_MAX LONG_MAX
#define INF_MIN LONG_MIN
using namespace std;
using Edge = pair<int, long long>;

int n, m, s, e;
long long money[100];
long long earn[100];
bool visited[100];
vector<Edge> line[100];

void BFS(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int nx = q.front(); q.pop();
        visited[nx] = true;
        for (int i = 0; i < (int)line[nx].size(); i++) {
            int tx = line[nx][i].first;
            if (visited[tx]) continue;
            q.push(tx);
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &s, &e, &m);
    for (int i = 0; i < m; i++) {
        int x, y; long long c;
        scanf("%d %d %lld", &x, &y, &c);
        line[x].push_back({ y, -c });
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &earn[i]);
        money[i] = INF_MIN;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)line[i].size(); j++) {
            line[i][j].second += earn[line[i][j].first];
        }
    }
    BFS(s);
    if (!visited[e]) {
        printf("gg\n"); return 0;
    }

    money[s] = earn[s];
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < (int)line[j].size(); k++) {
                int toward = line[j][k].first;
                long long cost = line[j][k].second;
                if (money[j] == INF_MAX) {
                    money[toward] = INF_MAX;
                }
                else if (money[j] != INF_MIN && money[toward] < money[j] + cost) {
                    if (i >= n) {
                        money[toward] = INF_MAX;
                    }
                    else {
                        money[toward] = money[j] + cost;
                    }
                }
            }
        }
    }

    if (money[e] == INF_MAX) {
        printf("Gee\n");
    }
    else {
        printf("%lld\n", money[e]);
    }

    return 0;
}
