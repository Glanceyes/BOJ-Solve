#include <cstdio>
using namespace std;

#define MAX 10000

int t;
long long d[MAX + 1][4];

int main() {
    d[1][1] = d[2][1] = d[2][2] = 1;
    d[3][1] = d[3][2] = d[3][3] = 1;

    for (int i = 4; i <= MAX; i += 1) {
        d[i][1] = d[i - 1][1];
        d[i][2] = d[i - 2][1] + d[i - 2][2];
        d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
    }

    scanf("%d", &t);

    while (t--) {
        int tmp;
        long long result = 0;
        scanf("%d", &tmp);
        for (int i = 1; i <= 3; i += 1) {
            result += d[tmp][i];
        }
        printf("%lld\n", result);
    }

    return 0;
}