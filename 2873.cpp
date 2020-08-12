#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int r, c;
int p[1000][1000];
string answer, rear;

void moving(string& s, char c, int num) {
    for (int i = 0; i < num; i += 1) {
        s += c;
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i += 1) {
        for (int j = 0; j < c; j += 1) {
            scanf("%d", &p[i][j]);
        }
    }

    // 가로가 홀수이면 지그재그로 쭉 모든 칸 방문
    if (r % 2 == 1) {
        for (int i = 0; i < r; i += 1) {
            if (i % 2) {
                moving(answer, 'L', c - 1);
                moving(answer, 'D', 1);
            }
            else {
                moving(answer, 'R', c - 1);
                if (i != r - 1) {
                    moving(answer, 'D', 1);
                }
            }
        }
    }
    // 세로가 홀수이면 지그재그로 쭉 모든 칸 방문
    else if (c % 2 == 1) {
        for (int i = 0; i < c; i += 1) {
            if (i % 2) {
                moving(answer, 'U', r - 1);
                moving(answer, 'R', 1);
            }
            else {
                moving(answer, 'D', r - 1);
                if (i != c - 1) {
                    moving(answer, 'R', 1);
                }
            }
        }
    }
    // 가로, 세로가 모두 짝수이면 최대 R * C - 1 칸만 방문 가능
    else {
        int c_x = 0, c_y = 1;
        for (int i = 0; i < r; i += 1) {
            for (int j = 0; j < c; j += 1) {
                if ((i + j) % 2) {
                    if (p[i][j] < p[c_x][c_y]) {
                        c_x = i; c_y = j;
                    }
                }
            }
        }
        int x1 = 0, y1 = 0, x2 = r - 1, y2 = c - 1;
        while (x2 - x1 > 1) {
            if (x1 / 2 < c_x / 2) {
                moving(answer, 'R', c - 1);
                moving(answer, 'D', 1);
                moving(answer, 'L', c - 1);
                moving(answer, 'D', 1);
                x1 += 2;
            }
            if (c_x / 2 < x2 / 2) {
                moving(rear, 'R', c - 1);
                moving(rear, 'D', 1);
                moving(rear, 'L', c - 1);
                moving(rear, 'D', 1);
                x2 -= 2;
            }
        }
        while (y2 - y1 > 1) {
            if (y1 / 2 < c_y / 2) {
                moving(answer, 'D', 1);
                moving(answer, 'R', 1);
                moving(answer, 'U', 1);
                moving(answer, 'R', 1);
                y1 += 2;
            }
            if (c_y / 2 < y2 / 2) {
                moving(rear, 'D', 1);
                moving(rear, 'R', 1);
                moving(rear, 'U', 1);
                moving(rear, 'R', 1);
                y2 -= 2;
            }
        }
        if (c_y == y1) {
            moving(answer, 'R', 1);
            moving(answer, 'D', 1);
        }
        else {
            moving(answer, 'D', 1);
            moving(answer, 'R', 1);
        }
        reverse(rear.begin(), rear.end());
        answer += rear;
    }

    for (int i = 0; i < (int)answer.length(); i += 1) {
        printf("%c", answer[i]);
    }

    return 0;
}