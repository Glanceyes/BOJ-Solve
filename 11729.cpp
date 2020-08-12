#include <cstdio>
using namespace std;

int n, k, cnt;

void move_count(int start, int through, int dest, int num) {
    if (num == 1) {
        cnt += 1; return;
    }
    move_count(start, dest, through, num - 1);
    move_count(start, through, dest, 1);
    move_count(through, start, dest, num - 1);

    return;
}

void move_pan(int start, int through, int dest, int num) {
    if (num == 1) {
        printf("%d %d\n", start, dest);
        return;
    }
    move_pan(start, dest, through, num - 1);
    move_pan(start, through, dest, 1);
    move_pan(through, start, dest, num - 1);

    return;
}

int main() {
    scanf("%d", &n);

    move_count(1, 2, 3, n);
    printf("%d\n", cnt);
    move_pan(1, 2, 3, n);
    return 0;
}