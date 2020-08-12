#include <cstdio>
using namespace std;

#define MAX_NUM 10000000

int n, m;
bool positive[MAX_NUM + 1];
bool negative[MAX_NUM + 1];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int temp; scanf("%d", &temp);
        if (temp == 0) {
            positive[temp] = negative[temp] = true;
        }
        else if (temp > 0) {
            positive[temp] = true;
        }
        else {
            negative[(-temp)] = true;
        }
    }


    scanf("%d", &m);

    for (int i = 0; i < m; i += 1) {
        int temp; scanf("%d", &temp);
        if (temp == 0) {
            if (positive[temp] == true) {
                printf("1 ");
            }
            else {
                printf("0 ");
            }
        }
        else if (temp > 0) {
            if (positive[temp] == true) {
                printf("1 ");
            }
            else {
                printf("0 ");
            }
        }
        else {
            if (negative[(-temp)] == true) {
                printf("1 ");
            }
            else {
                printf("0 ");
            }
        }
    }
    printf("\n");

    return 0;
}