#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int sl, tl, stg, stb;
string s, t, ts, tt;

int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    cin >> s;
    cin >> t;

    sl = s.length(); tl = t.length();
    stg = gcd(sl, tl); stb = (sl * tl) / stg;

    if (sl == tl) {
        printf("%d\n", !s.compare(t));
    }
    else {
        for (int i = 1; i <= (stb / sl); i += 1) {
            ts += s;
        }
        for (int i = 1; i <= (stb / tl); i += 1) {
            tt += t;
        }
        printf("%d\n", !ts.compare(tt));
    }
    return 0;
}