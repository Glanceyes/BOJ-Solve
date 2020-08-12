#include <iostream>
#include <string>
#include <vector>
using namespace std;

int l, n;
string s;

int update_fail(string s) {
    int s_size = (int)s.size();
    vector<int> fail(s_size);
    int j = 0; fail[0] = 0;

    for (int i = 1; i < s_size; i += 1) {
        while (j > 0 && s[i] != s[j]) {
            j = fail[j - 1];
        }
        if (s[i] == s[j]) {
            fail[i] = j + 1; j += 1;
        }
        else {
            fail[i] = 0;
        }
    }
    return fail[s_size - 1];
}

int main() {
    cin >> n;
    cin >> s;

    printf("%d\n", (int)s.size() - update_fail(s));

    return 0;
}