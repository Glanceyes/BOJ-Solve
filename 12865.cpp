#include <cstdio>

using namespace std;

#define MAX 100000
#define LARGER(a, b) (((a) > (b) ? (a) : (b)))

int n, k;
int W[101];
int V[101];
int D[MAX + 1];

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i += 1) {
        scanf("%d %d", &W[i], &V[i]);
    }
    
    for (int i = 1; i <= n; i += 1) {
        for (int j = k; j >= 1; j -= 1) {
            if (j - W[i] >= 0) {
                D[j] = LARGER(D[j], D[j - W[i]] + V[i]);
            }
        }
    }

    printf("%d\n", D[k]);

    return 0;
}