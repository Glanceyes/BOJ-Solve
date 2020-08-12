#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define INF_MAX LONG_MAX
#define INF_MIN LONG_MIN

using namespace std;
using ll = long long;

int n, m;
ll dist[101];
int before[101];
bool visited[101];
vector<int> route;
vector<pair<int, ll>> edges[101];

void BFS(int start) {
    queue<int> q; q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto tx : edges[x]) {
            if (!visited[tx.first]) {
                visited[tx.first] = true;
                q.push(tx.first);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; ll w; 
        scanf("%d %d %lld", &u, &v, &w);
        edges[u].push_back({ v, w });
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF_MIN;
    }

    BFS(1);
    if (!visited[n]) {
        printf("-1\n"); return 0;
    }

    dist[1] = 0; before[1] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto x : edges[j]) {
                int next = x.first;
                ll cost = x.second;
                if (dist[j] == INF_MAX) {
                    dist[next] = INF_MAX;
                }
                else if (dist[j] != INF_MIN &&
                    dist[next] < dist[j] + cost) {
                    if (i >= n) {
                        dist[next] = INF_MAX;
                    }
                    else {
                        dist[next] = dist[j] + cost;
                        before[next] = j;
                    }
                }
            }
        }
    }

    if (dist[n] == INF_MAX) {
        printf("-1\n");
    }
    else {
        int temp = n;
        route.push_back(temp);
        while (before[temp] != 1) {
            route.push_back(before[temp]);
            temp = before[temp];
        }
        route.push_back(1);
        reverse(route.begin(), route.end());
        for (auto x : route) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}