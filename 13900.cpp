#include <cstdio>
using namespace std;

#define n_max 100000

int n;
long long d[n_max + 1], s[n_max + 1];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        long long input; scanf("%lld", &input);
        for (int j = 0; j <= 10000; j += 1) {
            if (s[j] > 0) {
                d[j] += (input * j * s[j]);
            }
        }
        s[input] += 1;
    }

    long long sum = 0;
    for (int i = 0; i <= 10000; i += 1) {
        sum += d[i];
    }
    printf("%lld\n", sum);

    return 0;
}