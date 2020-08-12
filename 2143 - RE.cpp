#include <cstdio>
#include <vector>

using namespace std;

#define MAX 1000

int n, m;
int a[MAX + 1];
int b[MAX + 1];

long long t, counter;

void findB(int idx, int start, long long sum) {
    if (start >= m || (sum == t && idx >= 1)) {
        if (sum == t && idx >= 1) {
            counter += 1;
        }
        return;
    }
    if (idx == 0) {
        for (int i = start; i < m; i += 1) {
            findB(1, i + 1, sum + b[i]);
        }
    }
    else {
        findB(idx + 1, start + 1, sum + b[start]);
    }
}

void findA(int idx, int start, long long sum) {
    if (idx == 0) {
        for (int i = start; i < n; i += 1) {
            findA(1, i + 1, a[i]);
        }
    }
    else {
        findB(0, 0, sum);
        if (start < n) {
            findA(idx + 1, start + 1, sum + a[start]);
        }
        else {
            return;
        }
    }
}

int main() {
    scanf("%lld", &t);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i += 1) {
        scanf("%d", &b[i]);
    }

    findA(0, 0, 0);
    printf("%lld\n", counter);

    return 0;
}