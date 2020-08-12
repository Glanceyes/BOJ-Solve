#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> from(n, -1);
        vector<int> how(n, -1);
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(1 % n);
        dist[1 % n] = 0;
        how[1 % n] = 1;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = 0; i <= 1; i++) {
                int next = (now * 10 + i) % n;
                /* 
                    이미 앞에서 나머지가 이와 같은 수를 찾았다면
                    해당 BFS 탐색 경로를 더 이상 탐색하지 않기 위해
                    queue에 push하지 않고 멈추는 것 같은데,
                    해당 BFS 탐색 경로 뒤에 조건을 만족하는 수가
                    없다고 판단할 수 있는 이유는?
                    
                    ↓
                */
                if (dist[next] == -1) {
                    dist[next] = dist[now] + 1;
                    from[next] = now;
                    how[next] = i;
                    q.push(next);
                }
            }
        }
        if (dist[0] == -1) {
            cout << "BRAK" << '\n';
        }
        else {
            string ans = "";
            for (int i = 0; i != -1; i = from[i]) {
                ans += to_string(how[i]);
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        }
    }
    return 0;
}