#include <cstdio>
using namespace std;

long long n, sum;

int main() {
    scanf("%lld", &n);

    for (long long i = 1; i < n; i += 1) {
        sum += ((n * i) + i);
    }
    printf("%lld\n", sum);

    return 0;
}