#include <cstdio>
#include <math.h>
using namespace std;

long long a, b, c;
long long idx, result;

long long find(long long idx) {
    if (idx == 1) {
        return a % c;
    }
    long long temp;

    temp = find(idx / 2) % c;
    temp = (temp * temp) % c;
    if (idx % 2) {
        temp = (temp * (a % c)) % c;
    }

    return temp;
}

int main() {
    idx = 1; result = a;
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld\n", find(b));
   
    return 0;
}