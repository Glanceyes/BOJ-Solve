#include <cstdio>
using namespace std;

#define mod 10007
#define n_max 1000

int n, k;
long long d[n_max + 1][n_max + 1];

int main() {
    scanf("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i += 1) {
        d[i][0] = d[i][i] = 1;
    }

    for (int i = 2; i <= n; i += 1) {
        for (int j = 1; j < i; j += 1) {
            d[i][j] = ((d[i - 1][j - 1] % mod) + (d[i - 1][j] % mod)) % mod;
        }
    }

    printf("%lld\n", d[n][k]);

    return 0;
}