#include <cstdio>
using namespace std;

long long d[81];

int main() {
    int n; scanf("%d", &n);
    d[0] = 1; d[1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    printf("%lld\n", (d[n] + d[n - 1]) * 2);

    return 0;
}