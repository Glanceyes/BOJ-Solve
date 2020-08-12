#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        int k; scanf("%d", &k);
        vector<bool> invalid(k, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < k; i += 1) {
            char c; int x; getchar();
            scanf("%c %d", &c, &x);
            switch (c) {
            case 'I':
                max_heap.push(make_pair(x, i));
                min_heap.push(make_pair(x, i));
                break;
            case 'D':
                if (x == 1) {
                    if (!max_heap.empty()) {
                        while (invalid[max_heap.top().second]) {
                            max_heap.pop();
                            if (max_heap.empty()) break;
                        }
                        if (!max_heap.empty()) {
                            invalid[max_heap.top().second] = true;
                            max_heap.pop();
                        }
                    }
                }
                else if (x == -1) {
                    if (!min_heap.empty()) {
                        while (invalid[min_heap.top().second]) {
                            min_heap.pop();
                            if (min_heap.empty()) break;
                        }
                        if (!min_heap.empty()) {
                            invalid[min_heap.top().second] = true;
                            min_heap.pop();
                        }
                    }
                }
                break;
            }
        }
        if (!max_heap.empty()) {
            while (invalid[max_heap.top().second]) {
                max_heap.pop();
                if (max_heap.empty()) break;
            }
        }
        if (!min_heap.empty()) {
            while (invalid[min_heap.top().second]) {
                min_heap.pop();
                if (min_heap.empty()) break;
            }
        }
        if (max_heap.empty() || min_heap.empty()) {
            printf("EMPTY\n");
        }
        else {
            printf("%d %d\n", max_heap.top().first, min_heap.top().first);
        }
    }


    return 0;
}