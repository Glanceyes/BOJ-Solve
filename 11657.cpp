#include <cstdio>
#include <vector>
using namespace std;

#define INF 30000000000

int n, m;
bool cycle;
long long dist[501];
vector<pair<int, long long>> v[501];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; long long c;
        scanf("%d %d %lld", &a, &b, &c);
        v[a].push_back({ b, c });
    }

    dist[1] = 0;
    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
    }
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < (int)v[j].size(); k++) {
                int cur_pos = v[j][k].first;
                long long cur_cost = v[j][k].second;
                if (dist[j] != INF && dist[cur_pos] > dist[j] + cur_cost) {
                    dist[cur_pos] = dist[j] + cur_cost;
                    if (i == n) {
                        cycle = true;
                    }
                }
            }
        }
    }

    if (cycle) {
        printf("-1\n");
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) {
                printf("-1\n");
            }
            else {
                printf("%lld\n", dist[i]);
            }
        }
    }

    return 0;
}