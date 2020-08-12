#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

int n, c;
bool check[MAX];
vector<int> edge[MAX + 1];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    check[s] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (unsigned int i = 0; i < edge[x].size(); i += 1) {
            if (!check[edge[x][i]]) {
                check[edge[x][i]] = true;
                q.push(edge[x][i]);
            }
        }
    }
}

int main() {
    scanf("%d\n%d", &n, &c);
    for (int i = 0; i < c; i += 1) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }
    bfs(1);
    int result = 0;
    for (int i = 2; i <= n; i += 1) {
        if (check[i]) {
            result += 1;
        }
    }

    printf("%d\n", result);

    return 0;
}