#include <cstdio>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

int x, y, a0, a1, a2, n;

matrix operator* (const matrix& a, const matrix& b) {
    int a_row = (int)a.size();
    int a_col, b_col;
    a_col = b_col = a_row;
    matrix c(a_row, vector<long long>(b_col));
    for (int i = 0; i < a_row; i++) {
        for (int j = 0; j < b_col; j++) {
            for (int k = 0; k < a_col; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= 100;
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

void print_result(long long x) {
    if ((x % 100) < 10) {
        printf("0%lld\n", x % 100);
    }
    else {
        printf("%lld\n", x % 100);
    }
}

int main() {
    scanf("%d %d %d %d %d", &x, &y, &a0, &a1, &n);
    if (n == 0) {
        print_result(a0); return 0;
    }
    else if (n == 1) {
        print_result(a1); return 0;
    }
    matrix result = { {1, 0}, {0, 1} };
    matrix a = { {x, y}, {1, 0} };

    a2 = x * a1 + y * a0;

    matrix b = { {a2, a1}, {a1, a0} };

    find(n - 1, result, a);
    result = result * b;
    print_result(result[0][1]);

    return 0;
}