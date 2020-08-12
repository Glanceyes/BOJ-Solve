#include <cstdio>
using namespace std;

int n, k, end_x;
int depth[40001];
int height[40001];

int main() {
    scanf("%d", &n);

    int x = 0, y, prev_x = 0, prev_y = 0;
    for (int i = 0; i < n; i += 1) {
        scanf("%d %d", &x, &y);
        if (prev_x != x && prev_y == y) {
            for (int j = prev_x + 1; j <= x; j += 1) {
                depth[j] = y;
            }
        }
        prev_x = x; prev_y = y;
    }
    end_x = x;

    scanf("%d", &k);

    while (k--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for (int i = x1 + 1; i <= x2; i += 1) {
            height[i] = y1;
        }

        for (int i = x1; i > 0; i -= 1) {
            if (depth[i] > y1) {
                if (height[i] < y1) {
                    height[i] = y1;
                }
            }
            else {
                height[i] = y1 = depth[i];
            }
        }
        
        for (int i = x2; i <= end_x; i += 1) {
            if (depth[i] > y2) {
                if (height[i] < y2) {
                    height[i] = y2;
                }
            }
            else {
                height[i] = y2 = depth[i];
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= end_x; i += 1) {
        result += (depth[i] - height[i]);
    }

    printf("%d\n", result);

    return 0;
}