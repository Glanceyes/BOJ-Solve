#include <cstdio>
using namespace std;

int n, num;

int main() {
    scanf("%d", &n);
    n /= 3;

    for (int i = 1; i <= 1000 && i < n; i += 1) {
        for (int j = 1; j <= 1000 && j < n; j += 1) {
            if (n - i - j > 0) {
                num += 1;
            }
        }
    }

    printf("%d\n", num);
    return 0;
}