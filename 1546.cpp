#include <cstdio>
using namespace std;

int n;
double max, sum;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        double temp; scanf("%lf", &temp);
        if (max < temp) { max = temp; }
        sum += temp;
    }
    printf("%lf\n", (sum / max * 100) / n);

    return 0;
}