#include <cstdio>
using namespace std;

int n, m;
int parent[201], root_rank[201];

void swap(int& a, int& b) {
    int temp = a; a = b; b = temp;
}

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    else {
        return parent[x] = Find(parent[x]);
    }
}

void Union(int x, int y) {
    x = Find(x); y = Find(y);
    if (x == y) return;

    if (root_rank[x] < root_rank[y]) {
        swap(x, y);
    }
    parent[y] = x;
    if (root_rank[x] == root_rank[y]) {
        root_rank[x] = root_rank[y] + 1;
    }
}

int main() {
    int input;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i += 1) {
        parent[i] = i; root_rank[i] = 1;
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            scanf("%d", &input);
            if (input) {
                Union(i, j);
            }
        }
    }

    scanf("%d", &input);
    int prev = Find(input);
    for (int i = 1; i < m; i += 1) {
        scanf("%d", &input);
        if (Find(prev) != Find(input)) {
            printf("NO\n"); return 0;
        }
    }
    printf("YES\n");

    return 0;
}