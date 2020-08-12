#include <iostream>
#include <string>
using namespace std;

bool isChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

int fail[200001];

int main() {
    string s, n, k;
    cin >> s >> k;
    for (int i = 0, idx = 0; i < (int)s.size(); i++) {
        if (isChar(s[i])) {
            n.push_back(s[i]);
        }
    }


    fail[0] = 0;
    for (int i = 1, j = 0; i < (int)k.size(); i++) {
        while (j > 0 && k[i] != k[j]) {
            j = fail[j - 1];
        }
        if (k[i] == k[j]) {
            fail[i] = ++j;
        }
        else {
            fail[i] = 0;
        }
    }


    for (int i = 0, j = 0; i < (int)n.size(); i++) {
        while (j > 0 && n[i] != k[j]) {
            j = fail[j - 1];
        }
        if (n[i] == k[j]) {
            if (j == (int)k.size() - 1) {
                printf("1\n");
                return 0;
            }
            else {
                j += 1;
            }
        }
    }
    printf("0\n");

    return 0;
}