#include <cstdio>
using namespace std;

#define mod 1000000007

int s, n[3];
long long d[51][51][51][51];

long long find(int x, int a, int b, int c) {
    if (!x) {
        if (!a && !b && !c) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }

    if (d[x][a][b][c] != -1) {
        return d[x][a][b][c] % mod;
    }

    d[x][a][b][c] = 0;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a - 1, b, c)) % mod;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a, b - 1, c)) % mod;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a, b, c - 1)) % mod;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a - 1, b - 1, c)) % mod;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a - 1, b, c - 1)) % mod;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a, b - 1, c - 1)) % mod;
    d[x][a][b][c] = (d[x][a][b][c] % mod + find(x - 1, a - 1, b - 1, c - 1)) % mod;

    return d[x][a][b][c] % mod;
}

int main() {
    scanf("%d", &s);

    for (int i = 0; i < 3; i += 1) {
        scanf("%d", &n[i]);
    }

    for (int i = 0; i <= 50; i += 1) {
        for (int j = 0; j <= 50; j += 1) {
            for (int k = 0; k <= 50; k += 1) {
                for (int l = 0; l <= 50; l += 1) {
                    d[i][j][k][l] = -1;
                }
            }
        }
    }

    printf("%lld\n", find(s, n[0], n[1], n[2]));

    return 0;
}