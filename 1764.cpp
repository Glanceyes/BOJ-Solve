#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string name;
    set<string> hear, see;
    while (n--) {
        cin >> name;
        hear.insert(name);
    }
    while (m--) {
        cin >> name;
        if (hear.find(name) != hear.end()) {
            see.insert(name);
        }
    }
    cout << see.size() << '\n';
    for (auto it = see.begin(); it != see.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}