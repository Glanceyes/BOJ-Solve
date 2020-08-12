#include <cstdio>
using namespace std;

#define mod 1000000007

int n, m, p;
long long d[101][101];

long long find(int idx, int x) {
    if (idx == p) {
        if (!(n - x)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if (d[idx][x] != -1) {
        return d[idx][x];
    }

    long long result = 0;
    
    if (n - x > 0) {
        result += ((find(idx + 1, x + 1) % mod) * ((n - x) % mod)) % mod;
    }
    
    if (x - m > 0) {
        result += ((find(idx + 1, x) % mod) * ((x - m) % mod)) % mod;
    }

    d[idx][x] = result % mod;
    return d[idx][x];
}

int main() {
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i <= 100; i += 1) {
        for (int j = 0; j <= 100; j += 1) {
            d[i][j] = -1;
        }
    }
    
    printf("%lld\n", find(0, 0));

    return 0;
}