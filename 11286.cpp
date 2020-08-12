#include <cstdio>
#include <queue>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int x; scanf("%d", &x);
        if (x < 0) {
            heap.push(make_pair(-x, -1));
        }
        else if (x > 0) {
            heap.push(make_pair(x, 1));
        }
        else {
            if (!heap.empty()) {
                printf("%d\n", heap.top().first * heap.top().second);
                heap.pop();
            }
            else {
                printf("0\n");
            }
        }
    }

    return 0;
}