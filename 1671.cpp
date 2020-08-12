#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define N_MAX 102
#define EATEN 50
#define FLOW_MAX 987654321

struct shark {
    int size, velocity, intelligence;
    shark() {
        size = velocity = intelligence = 0;
    }
    shark(int x, int y, int z) {
        size = x;
        velocity = y;
        intelligence = z;
    }
};

int n;
int prv[N_MAX];
int flow[N_MAX][N_MAX];
int capacity[N_MAX][N_MAX];

shark sharks[N_MAX];
vector<int> eat[N_MAX];

int go(int start, int end) {
    int result = 0;
    while (1) {
        memset(prv, -1, sizeof(prv));
        queue<int> q; q.push(start);
        while (!q.empty() && prv[end] == -1) {
            int cur = q.front(); q.pop();
            if (cur == end) break;
            for (auto next : eat[cur]) {
                if (capacity[cur][next] - flow[cur][next] > 0 && prv[next] == -1) {
                    prv[next] = cur; q.push(next);
                }
            }
        }
        if (prv[end] == -1) break;
        int minFlow = FLOW_MAX;
        for (int i = end; i != start; i = prv[i]) {
            minFlow = min(minFlow, capacity[prv[i]][i] - flow[prv[i]][i]);
        }
        for (int i = end; i != start; i = prv[i]) {
            flow[prv[i]][i] += minFlow;
            flow[i][prv[i]] -= minFlow;
        }
        result += minFlow;
    }
    return result;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        eat[0].push_back(i); eat[i].push_back(0);
        capacity[0][i] = 2;

        sharks[i].size = x; 
        sharks[i].velocity = y;
        sharks[i].intelligence = z;
    }

    for (int i = 1; i <= n; i++) {
        shark temp = sharks[i];
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (sharks[j].size <= temp.size &&
                sharks[j].velocity <= temp.velocity &&
                sharks[j].intelligence <= temp.intelligence) {
                if (sharks[j].size == temp.size &&
                    sharks[j].velocity == temp.velocity &&
                    sharks[j].intelligence == temp.intelligence) {
                    if (i > j) {
                        eat[i].push_back(j + EATEN);
                        eat[j + EATEN].push_back(i);
                        capacity[i][j + EATEN] = 1;
                    }
                }
                else {
                    eat[i].push_back(j + EATEN);
                    eat[j + EATEN].push_back(i);
                    capacity[i][j + EATEN] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        eat[i + EATEN].push_back(N_MAX - 1);
        eat[N_MAX - 1].push_back(i + EATEN);
        capacity[i + EATEN][N_MAX - 1] = 1;
    }

    printf("%d\n", n - go(0, N_MAX - 1));

    return 0;
}