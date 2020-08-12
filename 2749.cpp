#include <cstdio>
using namespace std;

#define mod 1000000
#define cycle 1500000

long long n;
long long a[cycle];

int main() {
    scanf("%lld", &n);
    a[0] = 0; a[1] = 1;

    for (int i = 2; i < cycle; i += 1) {
        a[i] = (a[i - 1] + a[i - 2]) % mod;
    }

    printf("%lld\n", a[n % cycle] % mod);

    return 0;
}