#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 1001

int n; long long ans;
int parent[N_MAX];
int rnk[N_MAX];

struct flow {
    int a, b, cost;
    bool operator<(flow const& x) {
        if (cost < x.cost) return true;
        return false;
    }
};

int find(int x) {
    if (x == parent[x]) return x;
    return (parent[x] = find(parent[x]));
}

void swap(int& a, int& b) {
    int temp = a;
    a = b; b = temp;
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
    scanf("%d", &n);
    vector<flow> flows;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        for (int j = 1; j <= n; j++) {
            int cost; scanf("%d", &cost);
            flows.push_back({ i, j, cost });
        }
    }

    sort(flows.begin(), flows.end());
    for (auto iter : flows) {
        int u = iter.a;
        int v = iter.b;
        /* cycle 형성 안 하는 경우 */
        if (find(u) != find(v)) {
            merge(u, v);
            ans += (long long)iter.cost;
        }
    }
    printf("%lld\n", ans);

    return 0;
}