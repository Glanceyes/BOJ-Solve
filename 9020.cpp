#include <cstdio>
using namespace std;

int t, n;
bool p[10001];

int main() {
    scanf("%d", &t);

    p[0] = p[1] = true;
    for (int i = 2; i * i <= 10000; i += 1) {
        for (int j = i * 2; j <= 10000; j += i) {
            p[j] = true;
        }
    }

    while (t--) {
        scanf("%d", &n);

        int first = n / 2;

        while (first >= 1) {
            int second = n - first;
            if (!p[first] && !p[second]) {
                printf("%d %d\n", first, second);
                break;
            }
            first -= 1;
        }
    }
    return 0;
}