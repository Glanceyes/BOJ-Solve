#include <cstdio>
using namespace std;

int n, r, c, answer;

int exponent(int x) {
    int a = 1;
    while (x--) {
        a *= 2;
    }
    return a;
}

void result(int r1, int r2, int c1, int c2, int num) {
    if (r == r1 && c == c1 && r2 - r1 <= 1) {
        answer = num; return;
    }

    int m_r = r1 + (r2 - r1) / 2;
    int m_c = c1 + (c2 - c1) / 2;
    int temp = (r2 - r1 + 1) / 2;

    if (r <= m_r) {
        if (c <= m_c) {
            result(r1, m_r, c1, m_c, num);
        }
        else {
            result(r1, m_r, m_c + 1, c2, num + temp * temp);
        }
    }
    else {
        if (c <= m_c) {
            result(m_r + 1, r2, c1, m_c, num + temp * temp * 2);
        }
        else {
            result(m_r + 1, r2, m_c + 1, c2, num + temp * temp * 3);
        }
    }
    return;
}

int main() {
    scanf("%d %d %d", &n, &r, &c);

    int row_num, col_num;
    row_num = col_num = exponent(n);

    result(0, row_num - 1, 0, col_num - 1, 0);
    printf("%d\n", answer);

    return 0;
}