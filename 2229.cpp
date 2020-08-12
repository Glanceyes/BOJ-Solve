#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 1001

int n;
int d[N_MAX];

int main() {
    scanf("%d", &n);
    vector<int> student(n + 1);
    student[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &student[i]);
    }

    for (int i = 1; i <= n; i++) {
        int mx = 0, mn = 10000;
        for (int j = i; j > 0; j--) {
            mx = max(mx, student[j]);
            mn = min(mn, student[j]);
            d[i] = max(d[i], mx - mn + d[j - 1]);
        }
    }
    
    printf("%d\n", d[n]);

    return 0;
}