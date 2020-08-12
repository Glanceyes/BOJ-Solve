#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
using edge = pair<int, int>;

#define INF 100000000
int v, e, k;
int d[20001];
vector<edge> c[20001];

void find() {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ 0, k });

    while (!pq.empty()) {
        int nd = pq.top().first;
        int nv = pq.top().second;
        pq.pop();

        // 이미 보고자 하는 정점의 최소 거리가 작으면 볼 필요가 없음
        if (d[nv] < nd) continue;

        for (int i = 0; i < (int)c[nv].size(); i++) {
            int tv = c[nv][i].first;
            int td = nd + c[nv][i].second;
            
            if (d[tv] > td) {
                d[tv] = td; pq.push({ td, tv });
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &v, &e, &k); 

    for (int i = 0; i < e; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        c[x].push_back({ y, w });
    }

    for (int i = 1; i <= v; i++) {
        d[i] = INF;
    }
    
    d[k] = 0; find();

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n", d[i]);
        }
    }

    return 0;
}