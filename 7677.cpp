#include <cstdio>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator * (const matrix& a, const matrix& b) {
    int num = (int)a.size();
    matrix c(num, vector<long long>(num));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

matrix operator % (const matrix& a, long long p) {
    int num = (int)a.size();
    matrix c(num, vector<long long>(num));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            c[i][j] = a[i][j] % p;
        }
    }
    return c;
}


void find(long long x, matrix &result, matrix &temp) {
    while (x > 0) {
        if (x % 2) {
            result = result * temp;
            result = result % 10000;
        }
        temp = temp * temp;
        temp = temp % 10000;
        x /= 2;
    }

    return;
}

int main() {
    while (1) {
        long long n; scanf("%lld", &n);
        if (n == -1) break;
        matrix result = { {1, 1}, {1, 0} };
        matrix temp = { {1, 1}, {1, 0} };
        if (n == 0) {
            printf("0\n");
        }
        else {
            find(n - 1, result, temp);
            printf("%lld\n", result[0][1] % 10000);
        }
    }

    return 0;
}