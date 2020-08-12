#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    while (1) {
        string s; char c;
        while ((c = getchar()) != '\n') {
            s += c;
        }
        if (!s.compare("END")) {
            break;
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    
    return 0;
}