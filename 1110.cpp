#include <cstdio>
using namespace std;

int n, tmp, cnt;

int main() {
    scanf("%d", &n);

    tmp = n;
    do {
        int right = (tmp % 10) * 10;
        int sum = ((tmp / 10) + (tmp % 10)) % 10;
        tmp = right + sum; cnt += 1;
    } while (tmp != n);

    printf("%d\n", cnt);

    return 0;
}