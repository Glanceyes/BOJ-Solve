#include <cstdio>
using namespace std;

#define n_max 100000

int n, m;
long long d[n_max + 1];

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i += 1) {
        long long temp;
        scanf("%lld", &temp);
        d[i] = d[i - 1] + temp;
    }

    while (m--) {
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%lld\n", (d[j] - d[i - 1]));
    }

    return 0;
}