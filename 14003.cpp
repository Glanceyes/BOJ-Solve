#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define v_max 1000000

int n, cnt;
vector<int> v[v_max + 1], result;

int main() {
    scanf("%d", &n);

    vector<int> a(n), s;

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    s.push_back(a[0]); 
    cnt += 1; v[cnt].push_back(0);

    for (int i = 1; i < n; i += 1) {
        if (a[i] > s.back()) {
            s.push_back(a[i]); cnt += 1;
            v[cnt].push_back(i);
        }
        else {
            auto iter = lower_bound(s.begin(), s.end(), a[i]);
            v[iter - s.begin() + 1].push_back(i);
            *iter = a[i];
        }
    }
    printf("%d\n", cnt);

    int prev = v_max + 1;
    for (int i = cnt; i >= 1; i -= 1) {
        while (!v[i].empty()) {
            if (v[i].back() > prev) {
                v[i].pop_back();
            }
            else {
                prev = v[i].back();
                result.push_back(a[v[i].back()]);
                break;
            }
        }
    }
    
    reverse(result.begin(), result.end());
    for (int i = 0; i < (int)result.size(); i += 1) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}