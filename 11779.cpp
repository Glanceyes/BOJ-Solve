#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using line = pair<long long, int>;
#define MAX 10000000000

int n, m, a, b;
int trace[1001];
long long spend[1001];
vector<line> cost[1001];

void find() {
    priority_queue<line, vector<line>, greater<line>> pq;
    pq.push({ 0, a }); spend[a] = 0;

    while (!pq.empty()) {
        long long cur_spend = pq.top().first;
        int cur_city = pq.top().second;
        pq.pop();

        if (spend[cur_city] < cur_spend) continue;

        for (int i = 0; i < (int)cost[cur_city].size(); i++) {
            long long neigh_spend = cur_spend + cost[cur_city][i].first;
            int neigh_city = cost[cur_city][i].second;
            if (neigh_spend < spend[neigh_city]) {
                spend[neigh_city] = neigh_spend;
                trace[neigh_city] = cur_city;
                pq.push({ neigh_spend, neigh_city });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        spend[i] = MAX;
    }

    for (int i = 0; i < m; i++) {
        int start, end; long long fee;
        scanf("%d %d %lld", &start, &end, &fee);
        cost[start].push_back({ fee, end });
    }

    scanf("%d %d", &a, &b);

    find();

    vector<int> path; 
    int node = b, cnt = 1;
    while (node != a) {
        path.push_back(node);
        node = trace[node]; cnt++;
    }
    path.push_back(a);
   
    printf("%lld\n%d\n", spend[b], cnt);
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }

    return 0;
}