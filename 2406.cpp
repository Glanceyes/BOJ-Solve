#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using edge = tuple<int, int, int>;

#define N_MAX 1001

int n, m;
int parent[N_MAX];
int rank_size[N_MAX];
int cost[N_MAX][N_MAX];
bool direct[N_MAX][N_MAX];
vector<edge> edges;
vector<pair<int, int>> new_edges;

void swap(int& a, int& b) {
    int temp = a;
    a = b; b = temp;
}

int find(int x) {
    if (x == parent[x]) return x;
    return (parent[x] = find(parent[x]));
}

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (rank_size[x] < rank_size[y]) {
        swap(x, y);
    }
    parent[y] = x;
    if (rank_size[x] == rank_size[y]) {
        rank_size[x] = rank_size[y] + 1;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y; 
        scanf("%d %d", &x, &y);
        if (x > y) { swap(x, y); }
        direct[x][y] = true;
        merge(x, y);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (i < j && !direct[i][j]) {
                if (i != 1 && j != 1) {
                    edges.push_back({ cost[i][j], i, j });
                }
            }
        }
    }

    sort(edges.begin(), edges.end());
    int whole_cost = 0;
    for (auto e : edges) {
        int c, x, y; tie(c, x, y) = e;
        if (find(x) != find(y)) {
            merge(x, y);
            whole_cost += c;
            new_edges.push_back({ x, y });
        }
    }

    printf("%d %d\n", whole_cost, new_edges.size());
    for (auto e : new_edges) {
        printf("%d %d\n", e.first, e.second);
    }

    return 0;
}