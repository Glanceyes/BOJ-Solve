#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int a, b, c, sum;

void pour(int* w1, int* w2, int dst) {
    if (*w1 < (dst - *w2)) {
        *w2 += *w1;
        *w1 = 0;
    }
    else {
        *w1 -= dst - *w2;
        *w2 = dst;
    }
    return;
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    sum = c;

    map<pair<int, int>, int> water;
    vector<int> C;
    
    water.insert(make_pair(make_pair(0, 0), c));
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    C.push_back(c);
    while (!q.empty()) {
        int na = q.front().first;
        int nb = q.front().second;
        int nc = sum - na - nb;
        q.pop();
        
        int tmpa, tmpb, tmpc;

        for (int i = 0; i < 6; i += 1) {
            switch (i) {
            case 0:
                // a -> b
                tmpa = na; tmpb = nb; tmpc = nc;
                pour(&tmpa, &tmpb, b);
                break;
            case 1:
                // a -> c
                tmpa = na; tmpb = nb; tmpc = nc;
                pour(&tmpa, &tmpc, c);
                break;
            case 2:
                // b -> a
                tmpa = na; tmpb = nb; tmpc = nc;
                pour(&tmpb, &tmpa, a);
                break;
            case 3:
                // b -> c
                tmpa = na; tmpb = nb; tmpc = nc;
                pour(&tmpb, &tmpc, c);
                break;
            case 4:
                // c -> a
                tmpa = na; tmpb = nb; tmpc = nc;
                pour(&tmpc, &tmpa, a);
                break;
            case 5:
                // c -> b
                tmpa = na; tmpb = nb; tmpc = nc;
                pour(&tmpc, &tmpb, b);
                break;

            }
            if (water.find(make_pair(tmpa, tmpb)) == water.end()) {
                if (!tmpa) {
                    C.push_back(tmpc);
                }
                water.insert(make_pair(make_pair(tmpa, tmpb), tmpc));
                q.push(make_pair(tmpa, tmpb));
            }
        }
    }
    
    sort(C.begin(), C.end());
    for (unsigned int i = 0; i < C.size(); i += 1) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}