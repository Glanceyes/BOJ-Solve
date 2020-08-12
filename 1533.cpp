#include <cstdio>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

#define MOD 1000003

int n, s, e, t;

matrix operator *(const matrix& a, const matrix& b) {
    matrix c(n * 5, vector<long long>(n * 5));
    for (int i = 0; i < n * 5; i++) {
        for (int j = 0; j < n * 5; j++) {
            for (int k = 0; k < n * 5; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

void find(int k, matrix& result, matrix& a) {
    while (k) {
        if (k % 2) {
            result = result * a;
        }
        a = a * a; k /= 2;
    }
}

int main() {
    scanf("%d %d %d %d", &n, &s, &e, &t);

    matrix result(n * 5, vector<long long>(n * 5));
    matrix a(n * 5, vector<long long>(n * 5));
    s -= 1; e -= 1; getchar();

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 5; j++) {
            a[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                for (int k = 0; k < 5; k++) {
                    result[i * 5 + k][j * 5 + k] = 1;
                }
            }

            int val = (int)getchar() - '0';
            if (val <= 0) continue;
            if (val == 1) {
                a[i * 5][j * 5] = 1;
            }
            else if (val <= 5) {
                a[i * 5][j * 5 + val - 1] = 1;
            }
        }
        getchar();
    }

    find(t, result, a);
    printf("%lld\n", result[s * 5][e * 5] % MOD);

    return 0;
}