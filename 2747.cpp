#include <cstdio>
using namespace std;

long long n;
long long a[100];

long long fibonacci(long long idx) {
    if (idx == 0 || idx == 1) {
        return idx;
    }
    if (a[idx]) {
        return a[idx];
    }
    return (a[idx] = fibonacci(idx - 1) + fibonacci(idx - 2));
}


int main() {
    scanf("%lld", &n);

    printf("%lld\n", fibonacci(n));

    return 0;
}