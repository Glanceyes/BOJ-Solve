#include <cstdio>
#include <vector>
using namespace std;

#define mod 1000000007LL;

typedef vector<vector<long long>> matrix;
matrix result = { {1, 1}, {1, 0} };
matrix temp = { {1, 1}, {1, 0} };
long long n;

matrix operator * (const matrix& a, const matrix& b) {
    int s = a.size();
    matrix c(s, vector<long long>(s));
    for (int i = 0; i < s; i += 1) {
        for (int j = 0; j < s; j += 1) {
            for (int k = 0; k < s; k += 1) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

void find(long long x) {
    if (x == 1) {
        return;
    }
    find(x / 2);
    result = result * result;
    if (x % 2) {
        result = result * temp;
    }
}

int main() {
    scanf("%lld", &n);

    if (n == 0 || n == 1) {
        printf("%lld", n);
        return 0;
    }
    
    find(n); result[0][1] %= mod;

    printf("%lld\n", result[0][1]);

    return 0;
}
