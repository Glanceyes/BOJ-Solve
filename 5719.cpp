#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using road = pair<int, int>;

#define MAX_VALUE 100000000

int n, m, s, d;
int dist[500];
vector<int> trace[500];
int cost[500][500];

void find() {
    priority_queue<road, vector<road>, greater<road>> pq;
    pq.push({ 0, s }); dist[s] = 0;

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();

        if (dist[cur_pos] < cur_dist) continue;

        for (int i = 0; i < n; i++) {
            if (cost[cur_pos][i] == -1) continue;

            int neigh_pos = i;
            int neigh_dist = cur_dist + cost[cur_pos][i];
            
            if (dist[neigh_pos] >= neigh_dist) {
                if (dist[neigh_pos] > neigh_dist) {
                    trace[neigh_pos].clear();
                    pq.push({ neigh_dist, neigh_pos });
                }
                dist[neigh_pos] = neigh_dist;
                trace[neigh_pos].push_back(cur_pos);
            }
        }
    }
}

void erase_road() {
    queue<int> q; q.push(d);

    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (int i = 0; i < (int)trace[x].size(); i++) {
            int temp = trace[x][i];
            if (cost[temp][x] == -1) continue;
            cost[temp][x] = -1; q.push(temp);
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = -1;
            }
            trace[i].clear();
            dist[i] = MAX_VALUE;
        }

        scanf("%d %d", &s, &d);

        for (int i = 0; i < m; i++) {
            int u, v, p; scanf("%d %d %d", &u, &v, &p);
            cost[u][v] = p;
        }
        
        find(); erase_road(); 
        for (int i = 0; i < n; i++) {
            trace[i].clear(); dist[i] = MAX_VALUE;
        }

        find(); 
        if (dist[d] == MAX_VALUE) {
            printf("-1\n");
        }
        else {
            printf("%d\n", dist[d]);
        }
    }


    return 0;
}