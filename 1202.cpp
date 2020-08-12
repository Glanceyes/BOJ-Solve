#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef struct JEWEL {
    int m, v;
}Jewel;

int n, k;
long long answer;
vector<Jewel> jewel;
multiset<int> bag;

bool cmp(Jewel x, Jewel y) {
    return x.v > y.v;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i += 1) {
        Jewel t_jewel; 
        scanf("%d %d", &t_jewel.m, &t_jewel.v);
        jewel.push_back(t_jewel);
    }

    sort(jewel.begin(), jewel.end(), cmp);

    for (int i = 0; i < k; i += 1) {
        int t; scanf("%d", &t);
        bag.insert(t);
    }

    for (int i = 0; i < n; i += 1) {
       auto light = bag.lower_bound(jewel[i].m);
       if (light != bag.end()) {
           answer += jewel[i].v;
           bag.erase(light);
       }
    }

    printf("%lld\n", answer);

    return 0;
}