#include <cstdio>
using namespace std;

#define N_MAX 100000 + 1
#define T_MAX 100000 * 4 + 1

int n, q;
long long num[N_MAX];
long long tree[T_MAX];

void swap(int& a, int& b) {
    int temp = a;
    a = b; b = temp;
}

long long make_tree(int start, int end, int node) {
    if (start == end) {
        return tree[node] = num[start];
    }
    int mid = start + (end - start) / 2;
    return tree[node] = make_tree(start, mid, node * 2) + make_tree(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int idx, long long diff) {
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start != end) {
        int mid = start + (end - start) / 2;
        update(start, mid, node * 2, idx, diff);
        update(mid + 1, end, node * 2 + 1, idx, diff);
    }
}

long long sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = start + (end - start) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &num[i]);
    }

    make_tree(1, n, 1);
    while (q--) {
        int x, y, a; long long b;
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        if (x > y) swap(x, y);
        printf("%lld\n", sum(1, n, 1, x, y));
        update(1, n, 1, a, b - num[a]);
        num[a] = b;
    }

    return 0;
}