#include <cstdio>
using namespace std;

#define n_max 1000000

int n, b, c;
int a[n_max];
long long result;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    scanf("%d %d", &b, &c);

    for (int i = 0; i < n; i += 1) {
        a[i] -= b; result += 1;
    }

    for (int i = 0; i < n; i += 1) {
        if (a[i] > 0) {
            result += (a[i] / c);
            if (a[i] % c != 0) {
                result += 1;
            }
        }
    }
    printf("%lld\n", result);

    return 0;
}