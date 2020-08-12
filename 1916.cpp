#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using line = pair<int, long long>;
using Line = pair<long long, int>;

#define INIT 10000000000

int n, m;
int start_city, dest_city;
long long cost[1001];
vector<line> price[1001];

void find() {
    priority_queue<Line, vector<Line>, greater<Line>> pq;
    pq.push({ 0, start_city }); cost[start_city] = 0;
    
    while (!pq.empty()) {
        long long current_cost = pq.top().first;
        int current_city = pq.top().second; pq.pop();

        if (cost[current_city] < current_cost) continue;

        for (int i = 0; i < (int)price[current_city].size(); i++) {
            int neighbor_city = price[current_city][i].first;
            long long neighbor_cost = current_cost + price[current_city][i].second;
        
            if (cost[neighbor_city] > neighbor_cost) {
                cost[neighbor_city] = neighbor_cost;
                pq.push({ neighbor_cost, neighbor_city });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int start, dest; long long fee;
        scanf("%d %d %lld", &start, &dest, &fee);
        price[start].push_back({ dest, fee });
    }

    for (int i = 1; i <= n; i++) {
        cost[i] = INIT;
    }

    scanf("%d %d", &start_city, &dest_city);
    find();

    printf("%lld\n", cost[dest_city]);

    return 0;
}