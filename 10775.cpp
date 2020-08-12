#include <cstdio>
using namespace std;

int g, p, ans;
int Parent[100001];

int Find(int x) {
    if (x == Parent[x]) {
        return x;
    }
    else {
        return Parent[x] = Find(Parent[x]);
    }
}

void Union(int x, int y) {
    if (x == y) {
        return;
    }
    Parent[x] = y;
}

int main() {
    scanf("%d %d", &g, &p);

    for (int i = 0; i <= g; i += 1) {
        Parent[i] = i;
    }
    for (int i = 0; i < p; i += 1) {
        int input; scanf("%d", &input);
        int x = Find(input);
        if (!x) break;
        Union(x, Find(x - 1)); ans += 1;
    }
    printf("%d\n", ans);

    return 0;
}