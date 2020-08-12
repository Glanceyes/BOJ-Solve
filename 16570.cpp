#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, cnt;
int main() {
    scanf("%d", &n);
    vector<int> num(n), fail(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    reverse(num.begin(), num.end());

    fail[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && num[i] != num[j]) {
            j = fail[j - 1];
        }
        if (num[i] == num[j]) {
            j++; fail[i] = j;
        }
        else {
            fail[i] = 0;
        }
        if (ans <= fail[i]) {
            if (ans == fail[i]) {
                cnt += 1;
            }
            else {
                ans = fail[i];
                cnt = 1;
            }
        }
    }
    if (ans == 0) {
        printf("-1\n");
    }
    else {
        printf("%d %d\n", ans, cnt);
    }

    return 0;
}