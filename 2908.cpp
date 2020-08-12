#include <cstdio>
using namespace std;

int a, b;
int ra, rb;

int main() {
    scanf("%d %d", &a, &b);

    while (a) {
        ra = ra * 10 + a % 10;
        a /= 10;
    }

    while (b) {
        rb = rb * 10 + b % 10;
        b /= 10;
    }
    
    if (ra > rb) {
        printf("%d\n", ra);
    }
    else {
        printf("%d\n", rb);
    }

    return 0;
}