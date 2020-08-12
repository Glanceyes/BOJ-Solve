#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int cnt;
int main() {
    while (1) {
        int n; cin >> n;
        if (!n) break;
        vector<int> fail(n);
        string s; cin >> s;

        fail[0] = 0; cnt += 1;
        for (int i = 1, j = 0; i < (int)s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = fail[j - 1];
            }
            if (s[i] == s[j]) {
                fail[i] = (++j);
            }
            else {
                fail[i] = 0;
            }
        }

        printf("Test case #%d\n", cnt);
        for (int i = 1; i < (int)s.size(); i++) {
            if (fail[i] > 0 && (i + 1) % ((i + 1) - fail[i]) == 0) {
                printf("%d %d\n", (i + 1), (i + 1) / (i + 1 - fail[i]));
            }
        }
        printf("\n");
    }

    return 0;
}