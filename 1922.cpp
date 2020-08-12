#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using edge = tuple<int, int, int>;

#define N_MAX 1001

int n, m, ans;
int parent[N_MAX];
int rnk[N_MAX];
vector<edge> edges;

int find(int x) {
    if (x == parent[x]) return x;
    return (parent[x] = find(parent[x]));
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
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

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges.push_back({ c, a, b });
    }

    sort(edges.begin(), edges.end());

    for (auto x : edges) {
        int w, u, v; tie(w, u, v) = x;
        if (find(u) != find(v)) {
            merge(u, v);
            ans += w;
        }
    }

    printf("%d\n", ans);

    return 0;
}