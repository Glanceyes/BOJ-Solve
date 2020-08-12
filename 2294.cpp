#include <cstdio>
#include <vector>

using namespace std;

#define MAX 10000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int n, k;
int d[MAX + 1];
vector<int> c;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i += 1) {
        int tmp; scanf("%d", &tmp);
        c.push_back(tmp);
    }

    for (int i = 1; i <= k; i += 1) {
        d[i] = -1;
    }

    unsigned int num = c.size();
    for (unsigned int i = 0; i < num; i += 1) {
        for (int j = 1; j <= k; j += 1) {
            if (j - c[i] >= 0) {
                if (d[j - c[i]] != -1) {
                    if (d[j] == -1) {
                        d[j] = d[j - c[i]] + 1;
                    }
                    else {
                        d[j] = MIN(d[j], d[j - c[i]] + 1);
                    }
                }
            }
        }
    }
    printf("%d\n", d[k]);

    return 0;
}