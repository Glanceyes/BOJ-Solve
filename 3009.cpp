#include <cstdio>
using namespace std;

int d[2][1001];

int main() {
    for (int i = 0; i < 3; i += 1) {
        int x, y; scanf("%d %d", &x, &y);
        d[0][x] += 1; d[1][y] += 1;
    }

    int a[2];
    for (int i = 1; i <= 1000; i += 1) {
        for (int j = 0; j < 2; j += 1) {
            if (d[j][i] == 1) {
                a[j] = i;
            }
        }
    }
    printf("%d %d\n", a[0], a[1]);

    return 0;
}