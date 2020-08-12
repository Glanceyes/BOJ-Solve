#include <cstdio>
using namespace std;

#define N_MAX 30

int n, k;
char ans[N_MAX + 2];
bool d[N_MAX + 1][N_MAX + 1][N_MAX + 1][(30 * 29 / 2) + 1];

bool find(int i, int a, int b, int num) {
    if (i == n) {
        if (num == k) {
            return true;
        }
        else {
            return false;
        }
    }
    if (d[i][a][b][num]) {
        return false; // 이미 방문한 것에 대해서 다시 볼 필요 없음
    }
    d[i][a][b][num] = true;
    ans[i] = 'A';
    if (find(i + 1, a + 1, b, num)) {
        return true;
    }
    ans[i] = 'B';
    if (find(i + 1, a, b + 1, num + a)) {
        return true;
    }
    ans[i] = 'C';
    if (find(i + 1, a, b, num + a + b)) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);

    if (find(0, 0, 0, 0)) {
        printf("%s\n", ans);
    }
    else {
        printf("-1\n");
    }

    return 0;
}