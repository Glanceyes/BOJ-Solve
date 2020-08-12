#include <cstdio>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j < i; j += 1) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * (n - i) + 1; j += 1) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}