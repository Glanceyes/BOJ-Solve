#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define L_MAX 101

string s1, s2, s3;
int d[101][101][101];

int main() {
    cin >> s1; cin >> s2; cin >> s3;
    int l1, l2, l3;
    l1 = (int)s1.length(); 
    l2 = (int)s2.length(); 
    l3 = (int)s3.length();
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            for (int k = 1; k <= l3; k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    d[i][j][k] = max(d[i - 1][j][k], max(d[i][j - 1][k], d[i][j][k - 1]));
                }
            }
        }
    }

    cout << d[l1][l2][l3] << "\n";

    return 0;
}