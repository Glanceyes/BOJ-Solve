#include <cstdio>
using namespace std;

int n, k;
int a[10];

int main() {
    int answer = 0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    for (int i = n - 1; i >= 0; i -= 1) {
        answer += k / a[i];
        k %= a[i];
    }
    printf("%d\n", answer);

    return 0;
}