#include <cstdio>
#include <vector>
#include <string>
using namespace std;

#define INF 987654321

int l1, l2;
int ans = INF;

int main() {
    scanf("%d", &l1); getchar();
    vector<char> s(l1 * 2);
    vector<int> fail(l1 * 2);
    for (int i = 0; i < l1; i++) {
        s[i] = getchar();
    }


    fail[0] = 0; int j = 0;
    for (int i = 1; i < l1; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = fail[j - 1];
        }
        if (s[i] == s[j]) {
            j++; fail[i] = j;
        }
        else {
            fail[i] = 0;
        }
    }

    if (fail[l1 - 1] > 0 && l1 % (l1 - fail[l1 - 1]) == 0) {
        ans = l1 - fail[l1 - 1];
    }

    int start = fail[l1 - 1];

    for (int i = l1; i < l1 * 2; i++) {
        s[i] = s[start++];
        while (j > 0 && s[i] != s[j]) {
            j = fail[j - 1];
        }
        if (s[i] == s[j]) {
            j++; fail[i] = j;
        }
        else {
            fail[i] = 0;
        }
        if (fail[i] > 0 && (i + 1) % (i + 1 - fail[i]) == 0) {
            if (ans > (i + 1) - fail[i]) {
                ans = (i + 1) - fail[i];
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}