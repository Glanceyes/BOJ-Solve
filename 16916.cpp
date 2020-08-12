#include <iostream>
#include <string>
using namespace std;

int mod = 127;
int base = 256;

int hash_value(string s) {
    int ans = 0;
    for (char ch : s) {
        ans = (ans * base + ch) % mod;
    }
    return ans;
}

int match(string& s, string& p) {
    int n = s.length();
    int m = p.length();
    if (n < m) return 0;
    int hash_p = hash_value(p);
    int hash_s = hash_value(s.substr(0, m));
    int front = 1;
    for (int i = 0; i < m - 1; i += 1) {
        front = (front * base) % mod;
    }

    for (int i = 0; i < n - m; i += 1) {
        if (hash_p == hash_s) {
            if (s.substr(i, m) == p) {
                return 1;
            }
        }
        hash_s = hash_s - (s[i] * front) % mod;
        hash_s = (hash_s + mod) % mod;
        hash_s = ((hash_s * base) % mod + s[i + m]) % mod;
    }
    if (hash_p == hash_s) {
        if (s.substr(n - m, m) == p) {
            return 1;
        }
    }
    return 0;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << match(s, p) << "\n";

    return 0;
}