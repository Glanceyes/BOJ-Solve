#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using edge = pair<long long, int>;

#define MAX_VALUE (long long)1e12

struct d_edge {
    long long in;
    long long out;
    d_edge() {
        in = 0; out = 0;
    }
    d_edge(long long x, long long y) {
        in = x; out = y;
    }
};

int n, m;
long long cost[10002];
vector<edge> turnel[10002];

vector<int> direct; // 시작점(점 1)과 바로 연결된 1차 점들
d_edge direct_edge[10002]; // 1차 점들과 연결된 간선들

/*
시작점과 직접 바로 연결된 점들을 그룹 1과 그룹 2로 나눠서 분할정복 시행
*/

void find1(int bits) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    
    // 시작점에서 그룹 1로 가는 간선들 미리 push하여 방문한 것으로 처리
    for (int i = 0; i < (int)direct.size(); i++) {
        int temp = direct[i];
        if (temp & (1 << bits)) {
            pq.push({ direct_edge[temp].in, temp });
            cost[temp] = direct_edge[temp].in;
        }
    }
    while (!pq.empty()) {
        long long cur_cost = pq.top().first;
        int cur_pos = pq.top().second; pq.pop();
        if (cost[cur_pos] < cur_cost) continue;
        for (int i = 0; i < (int)turnel[cur_pos].size(); i++) {
            long long neigh_cost = cur_cost + turnel[cur_pos][i].first;
            int neigh_pos = turnel[cur_pos][i].second;
            if (cost[neigh_pos] > neigh_cost) {
                cost[neigh_pos] = neigh_cost;
                pq.push({ neigh_cost, neigh_pos });
            }
        }
    }
}

void find2(int bits) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    // 시작점에서 그룹 2로 가는 간선들 미리 push하여 방문한 것으로 처리
    for (int i = 0; i < (int)direct.size(); i++) {
        int temp = direct[i];
        if (!(temp & (1 << bits))) {
            pq.push({ direct_edge[temp].in, temp });
            cost[temp] = direct_edge[temp].in;
        }
    }
    while (!pq.empty()) {
        long long cur_cost = pq.top().first;
        int cur_pos = pq.top().second; pq.pop();
        if (cost[cur_pos] < cur_cost) continue;
        for (int i = 0; i < (int)turnel[cur_pos].size(); i++) {
            long long neigh_cost = cur_cost + turnel[cur_pos][i].first;
            int neigh_pos = turnel[cur_pos][i].second;
            if (cost[neigh_pos] > neigh_cost) {
                cost[neigh_pos] = neigh_cost;
                pq.push({ neigh_cost, neigh_pos });
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; long long c, d;
        scanf("%d %d %lld %lld", &a, &b, &c, &d);
        if (a != 1 && b != 1) {
            turnel[a].push_back({ c, b });
            turnel[b].push_back({ d, a });
        }
        if (a == 1) {
            direct.push_back(b);
            d_edge temp;
            temp.in = c; temp.out = d;
            direct_edge[b] = temp;
        }
        if (b == 1) {
            direct.push_back(a);
            d_edge temp;
            temp.in = d; temp.out = c;
            direct_edge[a] = temp;
        }
    }

    long long ans = MAX_VALUE;

    // 분할정복 시행
    for (int i = 0; i <= 12; i++) {
        for (int j = 1; j <= n; j++) {
            cost[j] = MAX_VALUE;
        }
        find1(i);
        for (int j = 0; j < (int)direct.size(); j++) {
            if (!(direct[j] & (1 << i))) {
                long long temp = cost[direct[j]] + direct_edge[direct[j]].out;
                ans = (temp < ans) ? (temp) : (ans);
            }
        }
        for (int j = 1; j <= n; j++) {
            cost[j] = MAX_VALUE;
        }
        find2(i);
        for (int j = 0; j < (int)direct.size(); j++) {
            if (direct[j] & (1 << i)) {
                long long temp = cost[direct[j]] + direct_edge[direct[j]].out;
                ans = (temp < ans) ? (temp) : (ans);
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}