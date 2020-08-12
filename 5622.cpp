#include <cstdio>
using namespace std;

int ans;

int main() {
    char c;
    while ((c = getchar()) != '\n') {
        if (c <= 'R') {
            ans += ((c - 'A') / 3) + 3;
        }
        else {
            switch (c) {
            case 'S':
                ans += 8; break;
            case 'T':
            case 'U':
            case 'V':
                ans += 9; break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                ans += 10; break;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}