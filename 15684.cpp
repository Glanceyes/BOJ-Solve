#include <cstdio>
using namespace std;

int n, m, h, answer = -1;
bool ladder[11][31];

int go(int move_i) {
    int move_j = 1;
    while (move_j <= h) {
        int ni = move_i - 1;
        if (ni >= 1) {
            if (ladder[ni][move_j]) {
                move_i = ni; move_j += 1; 
                continue;
            }
        }
        if (move_i + 1 <= n) {
            if (ladder[move_i][move_j]) {
                move_i += 1; move_j += 1;
                continue;
            }
        }
        move_j += 1;
    }
    return move_i;
}

void find(int idx, int start_i, int start_j) {
    if (idx <= 3) {
        bool flag = true;
        for (int i = 1; i <= n; i += 1) {
            if (go(i) != i) {
                flag = false; break;
            }
        }
        if (flag && (answer == -1 || answer > idx)) {
            answer = idx;
        }
    }
    if (idx >= 3) return;
    for (int i = start_i; i < n; i += 1) {
        for (int j = 1; j <= h; j += 1) {
            if (i == start_i && j == 1) j = start_j;
            if (!ladder[i][j] && !ladder[i - 1][j] && !ladder[i + 1][j]) {
                ladder[i][j] = true;
                find(idx + 1, i, j + 1);
                ladder[i][j] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &h);

    for (int i = 0; i < m; i += 1) {
        int tn, th; scanf("%d %d", &th, &tn);
        ladder[tn][th] = true;
    }

    find(0, 1, 1);
    printf("%d\n", answer);

    return 0;
}