#include <cstdio>
using namespace std;

int l, r, a;

int main() {
    scanf("%d %d %d", &l, &r, &a);

    while (a) {
        if (l > r) {
            r += 1;
        }
        else {
            l += 1;
        }
        a -= 1;
    }

    printf("%d\n", ((l > r) ? (r * 2) : (l * 2)));

    return 0;
}