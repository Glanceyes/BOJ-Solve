#include <cstdio>
#include <string.h>
using namespace std;

int n, answer = 99999;
bool coin[20][20];

void change_row(int row) {
    for (int i = 0; i < n; i += 1) {
        coin[row][i] = 1 - coin[row][i];
    }
    return;
}

void decide_row(int idx) {
    if (idx == n) {
        int sum = 0;
        for (int j = 0; j < n; j += 1) {
            int cnt = 0;
            for (int i = 0; i < n; i += 1) {
                if (coin[i][j]) {
                    cnt += 1;
                }
            }
            if (cnt <= n / 2) {
                sum += cnt;
            }
            else {
                sum += (n - cnt);
            }
        }
        if (sum < answer) {
            answer = sum;
        }
        return;
    }

    char temp[20][20];
    decide_row(idx + 1);
    memcpy(temp, coin, sizeof(coin));
    change_row(idx);
    decide_row(idx + 1);
    memcpy(coin, temp, sizeof(temp));
    
    return;
}

int main() {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            char input = getchar();
            switch (input) {
            case 'H': coin[i][j] = false; break;
            case 'T': coin[i][j] = true; break;
            }
        }
        getchar();
    }

    decide_row(0);
    printf("%d\n", answer);

    return 0;
}