#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i += 1) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n - 1; i += 1) {
        sum1 += x[i] * y[i + 1];
        sum2 += x[i + 1] * y[i];
    }
    sum1 += x[n - 1] * y[0];
    sum2 += x[0] * y[n - 1];

    long long ans = sum1 - sum2;
    if (ans < 0) {
        ans = -ans;
    }
    printf("%lld.", ans / 2);
    if (ans % 2 == 0) {
        printf("0\n");
    }
    else {
        printf("5\n");
    }

    return 0;
}