#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;


int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            v.push_back({ i, x });
        }
        int cnt = 0;
        while (!v.empty()) {
            int x = v.begin()->first;
            int y = v.begin()->second; 
            v.erase(v.begin());
            auto t = v.begin();
            for (; t != v.end(); t++) {
                if (t->second > y) {
                    break;
                }
            }
            if (t == v.end()) {
                cnt += 1;
                if (x == m) {
                    printf("%d\n", cnt); break;
                }
            }
            else {
                v.push_back({ x, y });
            }
        }
    }
}