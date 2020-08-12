#include<stdio.h>
using namespace std;

int n, jump = 0;
long long int count = 0;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i += jump) {
        jump = (((n - 1) / i) == 0 ? 1 : ((n - 1) % i) / ((n - 1) / i) + 1);
        count += (1 + (n - 1) / i) * jump;
    }

    printf("%lld\n", count);
    return 0;
}