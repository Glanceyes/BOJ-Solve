#include <cstdio>
using namespace std;

long long a, b, v, x;

int main() {
    scanf("%lld %lld %lld", &a, &b, &v);
    x = (v - b) / (a - b);
    if ((v - b) % (a - b)) {
        x += 1;
    }
    printf("%lld\n", x);

    return 0;
}