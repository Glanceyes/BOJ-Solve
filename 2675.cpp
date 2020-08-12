#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int t, r;

int main() {
    scanf("%d", &t);

    while (t--) {
        string s, p;
        scanf("%d", &r);
        cin >> s;
        for (unsigned int i = 0; i < s.length(); i += 1) {
            for (int j = 0; j < r; j += 1) {
                p += s[i];
            }
        }
        cout << p << "\n";
    }

    return 0;
}