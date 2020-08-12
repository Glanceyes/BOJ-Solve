#include <cstdio>
using namespace std;

long long a, b, sum, temp;

long long abs(long long x) {
    return ((x >= 0) ? (x) : (-x));
}

int main() {
    scanf("%lld %lld", &a, &b);
    if (a > b) {
        temp = a; a = b; b = temp;
    }
    sum = ((b - a + 1) * (b + a)) / 2;
    printf("%lld\n", sum);

    return 0;
}