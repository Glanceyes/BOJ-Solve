#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

bool compare(string& a, string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        return a < b;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i += 1) {
        string input; cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), compare);
    cout << v[0] << "\n";
    for (int i = 1; i < n; i += 1) {
        if (v[i].compare(v[i - 1])) {
            cout << v[i] << "\n";
        }
    }

    return 0;
}