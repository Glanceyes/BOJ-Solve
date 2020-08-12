#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        priority_queue<int, vector<int>> pq_max;
        priority_queue<int, vector<int>, greater<int>> pq_min;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if (pq_max.empty()) {
                pq_max.push(x);
            }
            else if (pq_max.top() < x) {
                pq_min.push(x);
                if (pq_min.size() > pq_max.size() - 1) {
                    pq_max.push(pq_min.top());
                    pq_min.pop();
                }
            }
            else {
                pq_max.push(x);
                if (pq_max.size() > pq_min.size() + 1) {
                    pq_min.push(pq_max.top());
                    pq_max.pop();
                }
            }
            if (i % 2) {
                ans.push_back(pq_max.top());
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 1; i <= (int)ans.size(); i++) {
            printf("%d ", ans[i - 1]);
            if (i % 10 == 0 && i != (int)ans.size()) printf("\n");
        }
        printf("\n");
    }

    return 0;
}