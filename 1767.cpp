#include <cstdio>
using namespace std;

#define mod 1000001

int n, m, k;
long long d[101][101][101];

long long find(int tn, int tm, int tk) {
    if (tk == 0) {
        return 1;
    }

    if (tn <= 0 || tm <= 0 || tk < 0) {
        return 0;
    }

    if (d[tn][tm][tk] != -1) {
        return d[tn][tm][tk];
    }

    d[tn][tm][tk] = 0;
    d[tn][tm][tk] += find(tn - 1, tm, tk) % mod;
    d[tn][tm][tk] += (find(tn - 1, tm - 1, tk - 1) * tm) % mod;
    d[tn][tm][tk] += (find(tn - 1, tm - 2, tk - 2) * (tm * (tm - 1)) / 2) % mod;
    d[tn][tm][tk] += find(tn - 2, tm - 1, tk - 2) * tm * (tn - 1) % mod;
    return (d[tn][tm][tk] %= mod);
}

int main() {
    scanf("%d\n%d\n%d", &n, &m, &k);

    for (int i = 0; i <= 100; i += 1) {
        for (int j = 0; j <= 100; j += 1) {
            for (int l = 0; l <= 100; l += 1) {
                d[i][j][l] = -1;
            }
        }
    }
    printf("%lld\n", find(n, m, k));

    return 0;
}