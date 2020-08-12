#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;
int a[26];

int main() {
    cin >> s;

    for (int i = 0; i < (int)s.size(); i += 1) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            a[s[i] - 'A'] += 1;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            a[s[i] - 'a'] += 1;
        }
    }

    int cnt = 0, idx = -1, a_max = -1;
    for (int i = 0; i < 26; i += 1) {
        if (a_max < a[i]) {
            a_max = a[i];
        }
    }
    for (int i = 0; i < 26; i += 1) {
        if (a_max == a[i]) {
            cnt += 1; idx = i;
        }
    }

    if (cnt == 1) {
        printf("%c\n", 'A' + idx);
    }
    else {
        printf("?\n");
    }


    return 0;
}