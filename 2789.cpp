#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    char c;
    while ((c = getchar()) != '\n') {
        switch (c) {
        case 'C':
        case 'A':
        case 'M':
        case 'B':
        case 'R':
        case 'I':
        case 'D':
        case 'G':
        case 'E':
            break;
        default:
            s += c;
            break;
        }
    }

    cout << s << "\n";

    return 0;
}