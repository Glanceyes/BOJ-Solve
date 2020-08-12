#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find(string s, int start) {
    int n = s.size();
    vector<int> temp(n);

    for (int i = 0; i < n; i += 1) {
        temp[i] = start;
    }

    int j = start;
    for (int i = start + 1; i < n; i += 1) {
        while (j > start && s[i] != s[j]) {
            j = temp[j - 1];
        }
        if (s[i] == s[j]) {
            temp[i] = j + 1; j += 1;
        }
        else {
            temp[i] = start;
        }
    }

    int temp_max = 0;
    for (int i = start; i < n; i += 1) {
        temp[i] -= start;
        if (temp_max < temp[i]) {
            temp_max = temp[i];
        }
    }
    return temp_max;
}

int main() {
    string s;
    cin >> s;

    int ans = 0, n = (int)s.size();
    for (int i = 0; i < n; i += 1) {
        int temp = 0;
        if (ans < (temp = find(s, i))) {
            ans = temp;
        }
    }
    printf("%d\n", ans);

    return 0;
}