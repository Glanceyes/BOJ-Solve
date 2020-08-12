#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using Path = pair<int, int>;

#define MAX 100000000

struct Road {
    int v, t;
    bool come;
    Road(int x, int y, int c) {
        v = x; t = y; come = c;
    }
};

int n, m, x;
int cost_go[1001];
int cost_come[1001];
vector<Road> time[1001];

void find(bool come) {
    priority_queue<Path, vector<Path>, greater<Path>> pq;
    int* cost = NULL; pq.push({ 0, x });
    (come) ? (cost = cost_go) : (cost = cost_come);
    cost[x] = 0;

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_village = pq.top().second;
        pq.pop();

        if (cost[cur_village] < cur_cost) continue;

        for (int i = 0; i < (int)time[cur_village].size(); i++) {
            if (come == time[cur_village][i].come) {
                int neigh_village = time[cur_village][i].v;
                int neigh_cost = cur_cost + time[cur_village][i].t;
                if (neigh_cost < cost[neigh_village]) {
                    cost[neigh_village] = neigh_cost;
                    pq.push({ neigh_cost, neigh_village });
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &x);

    for (int i = 1; i <= n; i++) {
        cost_come[i] = cost_go[i] = MAX;
    }

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        Road r1(end, cost, false), r2(start, cost, true);
        time[start].push_back(r1); time[end].push_back(r2);
    }

    find(false); find(true);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int temp = cost_go[i] + cost_come[i];
        if (temp > ans) ans = temp;
    }

    printf("%d\n", ans);

    return 0;
}