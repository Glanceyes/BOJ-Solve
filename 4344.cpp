#include <cstdio>
using namespace std;

int c, n;
int score[1000];

int main() {
    scanf("%d", &c);

    while (c--) {
        int sum = 0, cnt = 0;
        float avg = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i += 1) {
            scanf("%d", &score[i]);
            sum += score[i];
        }
        avg = (float)sum / n;
        for (int i = 0; i < n; i += 1) {
            if (score[i] > avg) {
                cnt += 1;
            }
        }
        printf("%.3f%%\n", ((float)(cnt * 100) / n));
    }

    return 0;
}