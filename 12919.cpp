#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main() {
    cin >> s;
    cin >> t;

    while (t.length() > s.length()) {
        if (t.back() == 'A') {
            if (*t.begin() == 'B') {
                string temp = t;
                reverse(temp.begin(), temp.end());
                temp.pop_back();
                while (temp.length() > s.length() && temp.back() == 'A') {
                    temp.pop_back();
                }
                if (!temp.compare(s)) {
                    printf("1\n"); return 0;
                }
            }
            t.pop_back();
        }
        else {
            if (*t.begin() == 'B') {
                reverse(t.begin(), t.end());
                t.pop_back();
            }
            else {
                break;
            }
        }
    }
    if (!t.compare(s)) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
    return 0;

    return 0;
}