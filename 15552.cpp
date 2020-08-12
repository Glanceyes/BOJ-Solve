#include <cstdio>
using namespace std;

int t;

int main() {
    scanf("%d", &t);

    while (t--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", x + y);
    }

    return 0;
}