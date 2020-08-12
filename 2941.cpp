#include <iostream>
#include <string>
using namespace std;

int cnt;
string s, a[8];

int main() {
    cin >> s;
    int temp = 0;

    a[0] = "c="; a[1] = "c-"; a[2] = "dz="; a[3] = "d-";
    a[4] = "lj"; a[5] = "nj"; a[6] = "s="; a[7] = "z=";

    for (int i = 0; i < 8; i += 1) {
        while ((temp = s.find(a[i])) != string::npos) {
            cnt += 1;
            for (int j = 0; j < (int)a[i].size(); j += 1) {
                s[temp + j] = '_';
            }
        }
    }
    
    for (int i = 0; i < (int)s.size(); i += 1) {
        if ((s[i] >= 'a' && s[i] <= 'z') || s[i] == '-' || s[i] == '=') {
            cnt += 1;
        }
    }
    cout << cnt << "\n";

    return 0;
}