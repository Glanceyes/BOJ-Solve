#include <cstdio>
using namespace std;

int n;
int cnt[2];
int paper[128][128];

void cut(int num, int start_x, int start_y) {
    if (num <= 0) return;
    int temp = paper[start_x][start_y];
    bool flag = true;
    for (int i = start_x; i < start_x + num; i += 1) {
        for (int j = start_y; j < start_y + num; j += 1) {
            if (temp != paper[i][j]) {
                flag = false; break;
            }
        }
        if (!flag) break;
    }
    if (flag) {
        cnt[temp] += 1; return;
    }
    else {
        int temp_num = num / 2;
        for (int i = 0; i < 2; i += 1) {
            for (int j = 0; j < 2; j += 1) {
                cut(temp_num, start_x + temp_num * i, start_y + temp_num * j);
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            scanf("%d", &paper[i][j]);
        }
    }

    cut(n, 0, 0);
    for (int i = 0; i < 2; i += 1) {
        printf("%d\n", cnt[i]);
    }

    return 0;
}