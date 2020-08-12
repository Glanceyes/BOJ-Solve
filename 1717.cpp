#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> parent, rk;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
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
    if (rk[x] < rk[y]) {
        swap(x, y);
    }
    parent[y] = x;
    if (rk[x] == rk[y]) {
        rk[x] = rk[y] + 1;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i += 1) {
        parent.push_back(i);
        rk.push_back(1);
    }

    for (int i = 0; i < m; i += 1) {
        int input, x, y; scanf("%d", &input);
        if (input) {
            scanf("%d %d", &x, &y);
            x = Find(x); y = Find(y);
            if (x == y) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        else {
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
    }

    return 0;
}