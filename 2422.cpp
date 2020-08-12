#include <cstdio>
using namespace std;

int n, m, ans;
int s[3];
bool c[201][201];

void find(int idx, int start) {
    if (idx == 3) {
        bool flag = true;
        for (int i = 0; i < 3; i += 1) {
            for (int j = i + 1; j < 3; j += 1) {
                if (c[s[i]][s[j]]) {
                    flag = false; break;
                }
            }
            if (!flag) break;
        }
        if (flag) {
            ans += 1;
        }
        return;
    }
    for (int i = start; i <= n; i += 1) {
        s[idx] = i; find(idx + 1, i + 1);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);

    while (m--) {
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        c[x1][x2] = true; c[x2][x1] = true;
    }

    find(0, 1);
    printf("%d\n", ans);

    return 0;
}