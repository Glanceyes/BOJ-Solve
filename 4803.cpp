#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 501

int parent[N_MAX];
int rnk[N_MAX];
bool isRoot[N_MAX];

bool visit[N_MAX];
bool check[N_MAX];
vector<int> edge[N_MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return (parent[x] = find(parent[x]));
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) swap(x, y);
    parent[y] = x;

    if (rnk[x] == rnk[y]) {
        rnk[x] = rnk[y] + 1;
    }
}

int isCycle(int x, int prv) {
    if (visit[x]) return true;
    visit[x] = true;
    for (int i = 0; i < (int)edge[x].size(); i++) {
        if (edge[x][i] == prv) continue;
        if (isCycle(edge[x][i], x)) return true;
    }
    return false;
}


int main() {
    int cnt = 1;
    while (1) {
        int n, m, ans = 0; scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        fill(parent, parent + N_MAX, 0);
        fill(rnk, rnk + N_MAX, 0);
        fill(isRoot, isRoot + N_MAX, false);
        fill(visit, visit + N_MAX, false);
        fill(check, check + N_MAX, false);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            edge[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int x, y; scanf("%d %d", &x, &y);
            edge[x].push_back(y);
            edge[y].push_back(x);
            if (find(x) != find(y)) {
                merge(x, y);
            }
        }
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            if (!isRoot[parent[i]]) {
                isRoot[parent[i]] = true;
                temp.push_back(parent[i]);
            }
        }

        for (int i = 0; i < (int)temp.size(); i++) {
            if (!isCycle(temp[i], -1)) {
                ans += 1;
            }
        }

        switch (ans) {
        case 0:
            printf("Case %d: No trees.\n", cnt); break;
        case 1:
            printf("Case %d: There is one tree.\n", cnt); break;
        default:
            printf("Case %d: A forest of %d trees.\n", cnt, ans); break;
        }
        cnt += 1;
    }

    return 0;
}