#include <cstdio>
#include <vector>
using namespace std;

#define MAX 10000

int n, k;
int d[MAX + 1];
vector<int> c;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i += 1) {
        int tmp; scanf("%d", &tmp);
        c.push_back(tmp);
    }

    d[0] = 1;
    for (unsigned int i = 0; i < c.size(); i += 1) {
        for (int j = 1; j <= k; j += 1) {
            if (j - c[i] >= 0) {
                d[j] += d[j - c[i]];
            }
        }
    }
    printf("%d\n", d[k]);

    return 0;
}