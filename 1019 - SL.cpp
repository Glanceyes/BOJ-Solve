#include <cstdio>
using namespace std;

int n, tmp, tn, digit, start = 1;
long long d[10];
long long dec, tdec;

void counter(int x, long long s) {
    while (x) {
        d[x % 10] += s;
        x /= 10;
    }
}

int main() {
    scanf("%d", &n);

    tmp = n; digit = 1; dec = 1;
    while (tmp) {
        tmp /= 10;
        digit += 1;
        dec *= 10;
    }
    digit -= 1; dec /= 10; tmp = tn = n;

    /*
    counter(n);
    for (int i = 0; i < 10; i += 1) {
        printf("%lld ", d[i]);
    }
    */
    tdec = 1;
    while (start <= tmp) {
        for (; start % 10 != 0 && start <= tmp; start += 1) {
            counter(start, tdec);
        }
        if (start > tmp) break;
        tmp = (tmp / 10) * 10;
        for (; tn >= tmp; tn--) {
            counter(tn, tdec);
        }
        for (int i = 0; i < 10; i += 1) {
            d[i] += (long long)(tn / 10 - 1 + 1) * tdec;
        }
        start /= 10; tdec *= 10; tn /= 10; tmp = tn;
    }

    for (int i = 0; i < 10; i += 1) {
        printf("%lld ", d[i]);
    }

    return 0;
}