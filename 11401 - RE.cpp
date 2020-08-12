#include <cstdio>
using namespace std;

#define mod 1000000007

long long n, k;

long long calculate(long long x, long long y) {
    if (x == y || y == 0) {
        return 1;
    }
    if (y == 1) {
        return x;
    }

    return ((calculate(x - 1, y - 1) % mod) + (calculate(x - 1, y) % mod)) % mod;
}

int main() {
    scanf("%lld %lld", &n, &k);

    printf("%lld\n", calculate(n, k));

    return 0;
}