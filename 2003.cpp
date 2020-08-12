#include <cstdio>

using namespace std;

#define MAX 10000

int n, counter;
long long m;

int a[MAX];

void find(long long left, int start) {
    if (start >= n || !left) {
        if (!left) {
            counter += 1;
        }
        return;
    }
    if (!start) {
        for (int i = start; i < n; i += 1) {
            if (a[i] <= left) {
                find(left - a[i], i + 1);
            }
        }
    }
    else {
        if (a[start] <= left && start < n) {
            find(left - a[start], start + 1);
        }
    }
}

int main() {
    scanf("%d %lld", &n, &m);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    find(m, 0);
    printf("%d\n", counter);

    return 0;
}