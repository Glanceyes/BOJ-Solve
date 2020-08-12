#include <cstdio>
using namespace std;

int n, x, idx;
int s[10000];
int v[10000];

int main() {
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &s[i]);
        if (s[i] < x) {
            v[idx] = s[i];
            idx += 1;
        }
    }

    for (int i = 0; i < idx; i += 1) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}