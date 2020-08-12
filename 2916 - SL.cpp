#include <iostream>
using namespace std;
int a[10];
bool d[360];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[0] = true;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 360; k++) {
            for (int j = 0; j < 360; j++) {
                if (d[j] == false) continue;
                d[(j - a[i] + 360) % 360] = true;
                d[(j + a[i]) % 360] = true;
            }
        }
    }
    while (m--) {
        int x;
        cin >> x;
        cout << (d[x] ? "YES" : "NO") << '\n';
    }
    return 0;
}