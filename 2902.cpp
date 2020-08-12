#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    char c = getchar();
    bool flag = false;
    s += c;
    while ((c = getchar()) != '\n') {
        if (c == '-') {
            flag = true; continue;
        }
        if (flag) {
            s += c; flag = false;
        }
    }
    cout << s << "\n";

    return 0;
}