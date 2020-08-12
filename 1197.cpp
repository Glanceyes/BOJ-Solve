#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using Edge = tuple<int, int, int>;

#define MAX_VALUE 10000

int v, e;
int rnk[MAX_VALUE + 1];
int parent[MAX_VALUE + 1];
vector<Edge> edge;

void swap(int& a, int& b) {
    int temp = a; a = b; b = temp;
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        swap(x, y);
    }
    parent[y] = x;
    if (rnk[x] == rnk[y]) {
        rnk[x] = rnk[y] + 1;
    }
}

int main() {
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back({ c, a, b });
    }

    long long ans = 0;

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
    sort(edge.begin(), edge.end());
    
    for (auto x : edge) {
        int w, u, v; tie(w, u, v) = x;
        if (find(u) != find(v)) {
            merge(u, v);
            ans += (long long)w;
        }
    }

    printf("%lld\n", ans);

    return 0;
}