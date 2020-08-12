#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 40

int n, s;
long long num[MAX];

int main() {
    int n1, n2;
    long long counter = 0;
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i += 1) {
        scanf("%lld", &num[i]);
    }
    
    n1 = n / 2; n2 = n - n1;
    vector<long long> s1(1 << n1);
    vector<long long> s2(1 << n2);
    
    for (int i = 0; i < (1 << n1); i += 1) {
        for (int j = 0; j < n1; j += 1) {
            if (i & (1 << j)) {
                s1[i] += num[j];
            }
        }
    }
    
    for (int i = 0; i < (1 << n2); i += 1) {
        for (int j = 0; j < n2; j += 1) {
            if (i & (1 << j)) {
                s2[i] += num[n1 + j];
            }
        }
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int idx1 = 0, idx2 = (1 << n2) - 1;
    long long sum = s1[idx1] + s2[idx2];

    while (idx1 < (1 << n1) && idx2 >= 0) {
        if (sum < s) {
            idx1 += 1;
            if (idx1 >= (1 << n1)) break;
            sum = s1[idx1] + s2[idx2];
        }
        else if (sum == s) {
            long long cnt1 = 1, cnt2 = 1;
            idx1 += 1; idx2 -= 1;
            while (idx1 < (1 << n1) && s1[idx1] == s1[idx1 - 1]){
                idx1 += 1;
                cnt1 += 1;
            }
            while (idx2 >= 0 && s2[idx2] == s2[idx2 + 1]) {
                idx2 -= 1;
                cnt2 += 1;
            }
            counter += cnt1 * cnt2;
            if (idx1 >= (1 << n1) || idx2 < 0) break;
            sum = s1[idx1] + s2[idx2];
        }
        else {
            idx2 -= 1;
            if (idx2 < 0) break;
            sum = s1[idx1] + s2[idx2];
        }
    }
    if (!s) counter -= 1;
    printf("%lld\n", counter);

    return 0;
}