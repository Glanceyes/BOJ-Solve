#include <cstdio>
#include <vector>
using namespace std;

#define N_MAX 51
#define MOD 1000000007

int n, m;
typedef vector<vector<long long>> matrix;

matrix operator * (const matrix& a, const matrix& b) {
    matrix c(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

void find(int d, matrix &result, matrix &temp) {
    while (d) {
        if (d & 1) {
            result = result * temp;
        }
        temp = temp * temp; d >>= 1;
    }
}


int main() {
    scanf("%d %d", &n, &m);
    matrix result(n + 1, vector<long long>(n + 1));
    matrix temp(n + 1, vector<long long>(n + 1));
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        result[a][b] = 1; temp[a][b] = 1;
        result[b][a] = 1; temp[b][a] = 1;
    }
    int d; scanf("%d", &d);
    if (!d) printf("0\n");
    else {
        find(d - 1, result, temp);
        printf("%lld\n", result[1][1] % MOD);
    }

    return 0;
}