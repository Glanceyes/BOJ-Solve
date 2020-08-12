#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

void find() {
    if (t.length() == s.length()) {
        if (s.compare(t) == 0) {
            printf("1\n");
            return;
        }
        else {
            printf("0\n");
            return;
        }
    }
    
    if (t.back() == 'A') {
        t.pop_back();
    }
    else {
        t.pop_back();
        reverse(t.begin(), t.end());
    }
    find();

    return;
}

/*
bool find(int idx, string ns) {
    if (idx == len) {
        if (ns.compare(t) == 0) {
            return true;
        }
        return false;
    }

    if (m[idx][ns]) {
        return false;
    }

    m[idx][ns] = true;

    ts = ns; ts += "A";

    if (find(idx + 1, ts)) {
        return true;
    }
    
    ts = ns; reverse(ts.begin(), ts.end()); ts += "B";

    if (find(idx + 1, ts)) {
        return true;
    }

    return false;
}
*/
int main() {
    cin >> s;
    cin >> t;

    find();

    return 0;
}