#include <cstdio>
using namespace std;

#define c_max 100000

int n;
int s[20];
bool v[20], c[c_max * 20 + 1];

void find(int idx, int start, int sum) {
    c[sum] = true;

    for (int i = start; i < n; i += 1) {
        if (!v[i]) {
            v[i] = true;
            find(idx + 1, i + 1, sum + s[i]);
            v[i] = false;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &s[i]);
    }

    find(0, 0, 0);
    
    for (int i = 0; i <= c_max * 20; i += 1) {
        if (!c[i]) {
            printf("%d\n", i); break;
        }
    }

    return 0;
}