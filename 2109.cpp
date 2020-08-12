#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Lecture {
    int p, d;
};

int n, answer;
vector<Lecture> day;

bool cmp(Lecture x, Lecture y) {
    return (x.d > y.d) || (x.d == y.d && x.p > y.p);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        Lecture temp;
        scanf("%d %d", &temp.p, &temp.d);
        day.push_back(temp);
    }

    sort(day.begin(), day.end(), cmp);
    
    priority_queue<int> pq;
    for (int i = 10000, idx = 0; i >= 1; i -= 1) {
        while (idx < n) {
            if (day[idx].d == i) {
                pq.push(day[idx].p); idx += 1;
            }
            else { break; }
        }
        if (!pq.empty()) {
            answer += pq.top(); pq.pop();
        }
    }

    printf("%d\n", answer);

    return 0;
}