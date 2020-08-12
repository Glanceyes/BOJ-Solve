#include <cstdio>
using namespace std;

int a, b, num = 1, idx = 1, sum;

int main() {
    scanf("%d %d", &a, &b);

    while (idx <= b) {
        for (int i = 1; i <= num && idx <= b; i += 1, idx += 1) {
            if (idx >= a) {
                sum += num;
            }
        }
        num += 1;
    }

    printf("%d\n", sum);

    return 0;
}