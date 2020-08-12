#include <cstdio>
#include <vector>
using namespace std;

#define MOD 1000000007

typedef vector<vector<long long>> matrix;

int d;

matrix mat = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

matrix operator * (const matrix& a, const matrix& b) {
    matrix c(8, vector<long long>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

void go(int x, matrix& a, matrix& result) {
    while (x > 0) {
        if (x % 2) {
            result = result * a;
        }
        a = a * a; x /= 2;
    }
}

int main() {
    matrix result(8, vector<long long>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == j) result[i][j] = 1;
            else result[i][j] = 0;
        }
    }
    scanf("%d", &d);
    go(d, mat, result);
    printf("%lld\n", result[0][0] % MOD);

    return 0;
}