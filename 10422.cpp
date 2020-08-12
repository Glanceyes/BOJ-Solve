#include <cstdio>
using namespace std;

#define L_MAX 5000
#define MOD 1000000007

int t, l;
long long d[L_MAX + 1];

int main() {
    scanf("%d", &t);

    d[0] = 1;
    for (int i = 2; i <= L_MAX; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            d[i] = (d[i] + d[j - 2] * d[i - j]) % MOD;
        }
    }

    while (t--) {
        scanf("%d", &l);
        printf("%lld\n", d[l] % MOD);
    }

    return 0;
}