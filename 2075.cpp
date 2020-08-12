#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; scanf("%d", &x);
            if ((int)pq.size() >= n) {
                if (x > pq.top()) {
                    pq.pop(); pq.push(x);
                }
            }
            else {
                pq.push(x);
            }
        }
    }

    printf("%d\n", pq.top());

    return 0;
}