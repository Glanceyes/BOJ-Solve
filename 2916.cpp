#include <cstdio>
using namespace std;

int n, k, num, want;
bool made[360];

int main() {
    scanf("%d %d", &n, &k);
    made[0] = true;

    for (int i = 0; i < n; i += 1) {
        int temp;  scanf("%d", &temp);
        made[temp] = true; num += 1;
    }

    for (int i = 0; i < num && num < 360; i += 1) {
        for (int j = 0; j < 360; j += 1) {
            for (int k = 0; k < 360; k += 1) {
                if (!made[j] || !made[k]) continue;
                if (!made[(j - k + 360) % 360]) {
                    made[(j - k + 360) % 360] = true; num += 1;
                }
                if (!made[(j + k) % 360]) {
                    made[(j + k) % 360] = true; num += 1;
                }
            }
        }
    }

    while (k--) {
        scanf("%d", &want);
        (made[want]) ? (printf("YES\n")) : (printf("NO\n"));
    }

    return 0;
}