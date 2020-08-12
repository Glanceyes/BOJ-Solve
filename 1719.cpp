#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using Edge = pair<int, int>;

#define MAX_VALUE 100000000

int n, m;
int cost[201];
int trace[201];
vector<Edge> edge[201];

void find(int start) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (int i = 0; i < (int)edge[start].size(); i++) {
        auto x = edge[start][i];
        cost[x.second] = x.first;
        trace[x.second] = x.second;
        pq.push({ x.first, x.second });
    }
    cost[start] = 0; trace[start] = start;

    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        if (cost[x.second] < x.first) continue;
        for (int i = 0; i < (int)edge[x.second].size(); i++) {
            auto y = edge[x.second][i];
            if (cost[y.second] > y.first + x.first) {
                cost[y.second] = y.first + x.first;
                trace[y.second] = trace[x.second];
                pq.push({ y.first + x.first, y.second });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back({ c, b });
        edge[b].push_back({ c, a });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[j] = MAX_VALUE;
            trace[j] = 0;
        }
        find(i);
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                printf("- ");
            }
            else {
                printf("%d ", trace[j]);
            }
        }
        printf("\n");
    }

    return 0;
}