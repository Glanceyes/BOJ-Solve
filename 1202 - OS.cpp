#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct JEWEL {
    int m, v;
} jewel;

int n, k;
long long answer;

bool cmp(jewel x, jewel y) {
    return x.m < y.m;
}

int main() {
    scanf("%d %d", &n, &k);

    vector<jewel> steal(n);
    vector<int> bag(k);

    for (int i = 0; i < n; i += 1) {
        scanf("%d %d", &steal[i].m, &steal[i].v);
    }

    for (int i = 0; i < k; i += 1) {
        scanf("%d", &bag[i]);
    }

    sort(steal.begin(), steal.end(), cmp);
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;

    for (int i = 0, idx = 0; i < k; i += 1) {
        while (idx < n) {
            if (steal[idx].m <= bag[i]) {
                pq.push(steal[idx].v); idx += 1;
            }
            else { break; }
        }
        if (!pq.empty()) {
            answer += pq.top(); pq.pop();
        }
    }
    printf("%lld\n", answer);

    return 0;
}