#include <cstdio>
#include <algorithm>
using namespace std;
 
int n, sum, p_num, n_num;
int pos[10000], neg[10000];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        if (input > 0) {
            pos[p_num] = input; p_num += 1;
        }
        else {
            neg[n_num] = input; n_num += 1;
        }
    }

    sort(pos, pos + p_num);
    sort(neg, neg + n_num);

    int temp = 0;
    for (int i = p_num - 1; i >= 0; i -= 1) {
        if (!temp) {
            temp = pos[i];
        }
        else {
            if (pos[i] == 1) {
                sum += (temp + pos[i]); temp = 0;
            }
            temp *= pos[i]; sum += temp; temp = 0;
        }
    }
    sum += temp; temp = 0;

    for (int i = 0; i < n_num; i += 1) {
        if (!temp) {
            temp = neg[i];
        }
        else {
            if (!neg[i]) {
                temp = 0; continue;
            }
            else {
                temp *= neg[i]; sum += temp; temp = 0;
            }
        }
    }
    sum += temp;
    
    printf("%d\n", sum);

    return 0;
}