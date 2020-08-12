#include <cstdio>
using namespace std;

int n, answer;
int num[1000];
int box[1000];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < n; i += 1) {
        box[i] = 1;
        for (int j = 0; j < i; j += 1) {
            if (num[j] < num[i] && box[i] < box[j] + 1) {
                box[i] = box[j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i += 1) {
        if (answer < box[i]) {
            answer = box[i];
        }
    }

    printf("%d\n", answer);

    return 0;
}