#include <cstdio>
using namespace std;

int t;

int main() {
    scanf("%d", &t);
    for (int i = 1; i <= t; i += 1) {
        int tm1, tm2; scanf("%d %d", &tm1, &tm2);
        printf("Case #%d: %d\n", i, tm1 + tm2);
    }
    return 0;
}