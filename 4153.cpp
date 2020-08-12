#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (1) {
        vector<long long> n(3);
        for (int i = 0; i < 3; i += 1) {
            scanf("%lld", &n[i]);
        }
        if (!n[0] && !n[1] && !n[2]) break;
        sort(n.begin(), n.end());

        if ((n[2] * n[2]) == (n[1] * n[1]) + (n[0] * n[0])) {
            printf("right\n");
        }
        else {
            printf("wrong\n");
        }
    }

    return 0;
}