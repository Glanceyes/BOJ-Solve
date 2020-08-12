#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    set<string> s;
    while (n--) {
        string name, enter;
        cin >> name >> enter;
        if (!enter.compare("enter")) {
            s.insert(name);
        }
        else {
            if (s.find(name) != s.end()) {
                s.erase(s.find(name));
            }
        }
    }
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}