#include <cstdio>
using namespace std;

int t;
int main() {
    scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        long long result = 1;
        int l2 = (n < m - n) ? n : m - n;
        int l1 = (n < m - n) ? m - n : n;
        for (long long i = m, j = 1; i > l1; i--, j++) {
            result *= i;
            if (j <= l2) {
                result /= j;
            }
        }
        printf("%lld\n", result);
    }


    return 0;
}