#include <cstdio>
using namespace std;

int v, a, b;
int main() {
    scanf("%d\n", &v);
    while (v--) {
        char c= getchar();
        if (c == 'A') a += 1;
        if (c == 'B') b += 1;
    }
    if (a > b) {
        printf("A\n");
    }
    else if (b > a) {
        printf("B\n");
    }
    else {
        printf("Tie\n");
    }


    return 0;
}