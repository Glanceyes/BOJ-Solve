#include <cstdio>
#include <queue>
using namespace std;

int n, min_hn, max_hn;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        int x; scanf("%d", &x);
        if (max_heap.empty()) {
            max_heap.push(x); max_hn += 1;
        }
        else {
            if (x > max_heap.top()) {
                min_heap.push(x); min_hn += 1;
            }
            else {
                max_heap.push(x); max_hn += 1;
            }
            if (max_hn > min_hn + 1) {
                int temp = max_heap.top();
                max_heap.pop(); max_hn -= 1;
                min_heap.push(temp); min_hn += 1;
            }
            else if (max_hn < min_hn) {
                int temp = min_heap.top();
                min_heap.pop(); min_hn -= 1;
                max_heap.push(temp); max_hn += 1;
            }
        }
        printf("%d\n", max_heap.top());
    }

    return 0;
}