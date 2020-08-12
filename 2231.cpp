#include <cstdio>
using namespace std;

int n;

int digit_sum(int x) {
    int sum = 0;
    while (x) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i += 1) {
        if (n == i + digit_sum(i)) {
            printf("%d\n", i); return 0;
        }
    }
    printf("0\n");

    return 0;
}