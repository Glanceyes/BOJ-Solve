#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define N_MAX 32001

int n, m;
int indegree[N_MAX];
vector<int> edges[N_MAX];
vector<int> ans;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        indegree[b] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int here = q.front(); q.pop();
        ans.push_back(here);
        for (auto next : edges[here]) {
            indegree[next] -= 1;
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }

    for (auto x : ans) {
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}