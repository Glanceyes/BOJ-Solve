#include <cstdio>
using namespace std;

int x, y, w, h;

int main() {
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int dx1, dx2, dy1, dy2;
    dx1 = x; dx2 = w - x;
    dy1 = y; dy2 = h - y;
    dx1 = (dx1 < dx2) ? dx1 : dx2;
    dy1 = (dy1 < dy2) ? dy1 : dy2;
    printf("%d\n", (dx1 < dy1) ? (dx1) : (dy1));

    return 0;
}