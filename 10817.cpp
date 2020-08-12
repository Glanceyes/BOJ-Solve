#include <cstdio>
using namespace std;

int a, b, c;

int main() {
    int tmp1 = 0, tmp2 = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) {
        tmp1 = a;
        tmp2 = b;
    }
    else {
        tmp1 = b;
        tmp2 = a;
    }

    if (tmp1 < c) {
        tmp2 = tmp1;
        tmp1 = c;
    }
    else {
        if (tmp2 < c) {
            tmp2 = c;
        }
    }

    printf("%d\n", tmp2);

    return 0;
}