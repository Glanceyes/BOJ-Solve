#include <cstdio>
#include <limits.h>
using namespace std;

int n;
int min_answer = INT_MAX;
int max_answer = INT_MIN;
int num[11];
int op[5];

void find(int idx, int sum) {
    if (idx == n) {
        if (sum < min_answer) {
            min_answer = sum;
        }
        if (sum > max_answer) {
            max_answer = sum;
        }
        return;
    }
    for (int i = 1; i <= 4; i += 1) {
        if (op[i] <= 0) continue;
        op[i] -= 1;
        switch (i) {
        case 1: find(idx + 1, sum + num[idx]); break;
        case 2: find(idx + 1, sum - num[idx]); break;
        case 3: find(idx + 1, sum * num[idx]); break;
        case 4: find(idx + 1, sum / num[idx]); break;
        }
        op[i] += 1;
    }
    return;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }

    for (int i = 1; i <= 4; i += 1) {
        int op_num; scanf("%d", &op_num);
        op[i] = op_num;
    }

    find(1, num[0]);

    printf("%d\n%d\n", max_answer, min_answer);

    return 0;
}