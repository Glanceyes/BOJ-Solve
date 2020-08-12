#include <cstdio>
using namespace std;

int n, result;
int w[11];
bool v[11];

void find(int idx, int energy) {
    if (idx == n - 2) {
        if (result < energy) {
            result = energy;
        }
        return;
    }
    for (int i = 2; i < n; i += 1) {
        if (!v[i]) {
            v[i] = true; 
            int tmp1 = i - 1, tmp2 = i + 1;
            while (tmp1 >= 1 && v[tmp1]) {
                tmp1 -= 1;
            }
            while (tmp2 <= n && v[tmp2]) {
                tmp2 += 1;
            }
            find(idx + 1, energy + (w[tmp1] * w[tmp2]));
            v[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1) {
        scanf("%d", &w[i]);
    }
    find(0, 0);
    printf("%d\n", result);

    return 0;
}