#include <cstdio>
using namespace std;

int a[10], m, p;

int main() {
    for (int i = 1; i < 10; i += 1) {
        scanf("%d", &a[i]);
        if (m < a[i]) {
            m = a[i]; p = i;
        }
    }
    printf("%d\n%d\n", m, p);

    return 0;
}