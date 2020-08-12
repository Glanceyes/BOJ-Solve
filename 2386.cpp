#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char c, temp;

int main() {
    while ((c = getchar()) != '#') {
        getchar(); string s; int cnt = 0;
        while ((temp = getchar()) != '\n') {
            s += temp;
        }
        bool flag = false;
        if (c >= 'a' && c <= 'z') {
            flag = true;
        }

        for (unsigned int i = 0; i < s.length(); i += 1) {
            if (flag) {
                if (s[i] == c || s[i] + 32 == c) {
                    cnt += 1;
                }
            }
            else {
                if (s[i] == c || s[i] - 32 == c) {
                    cnt += 1;
                }
            }
        }
        cout << c << " " << cnt << "\n";
    } 

    return 0;
}