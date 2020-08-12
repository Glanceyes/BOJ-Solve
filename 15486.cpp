#include <cstdio>
using namespace std;

#define N_MAX 1500000
#define MAX(a, b) (((a) > (b) ? (a) : (b)))

int n;
int t[N_MAX + 2];
int p[N_MAX + 2];
int d[N_MAX + 2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i += 1) {
        scanf("%d %d", &t[i], &p[i]);
    }

    for (int i = 1; i <= n; i += 1) {
        if (i + t[i] <= n + 1) {
            d[i + t[i]] = MAX(d[i + t[i]], d[i] + p[i]);
        }
        d[i + 1] = MAX(d[i + 1], d[i]);
    }

    printf("%d\n", d[n + 1]);
    return 0;
}