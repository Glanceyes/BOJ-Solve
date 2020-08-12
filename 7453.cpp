#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 4000

int n;
int a[MAX], b[MAX], c[MAX], d[MAX];
vector<int> sum1, sum2;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            sum1.push_back(a[i] + b[j]);
            sum2.push_back(c[i] + d[j]);
        }
    }

    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    reverse(sum1.begin(), sum1.end());

    long long counter = 0;
    unsigned int index1, index2;
    unsigned int size1 = sum1.size();
    unsigned int size2 = sum2.size();
    index1 = index2 = 0;

    while (index1 < size1 && index2 < size2) {
        if (sum1[index1] + sum2[index2] < 0) {
            index2 += 1;
        }
        else if (sum1[index1] + sum2[index2] > 0) {
            index1 += 1;
        }
        else {
            long long cnt1, cnt2;
            cnt1 = cnt2 = 1;
            index1 += 1; index2 += 1;
            if (index1 < size1) {
                while (sum1[index1] == sum1[index1 - 1]) {
                    index1 += 1; cnt1 += 1;
                    if (index1 >= size1) break;
                }
            }
            if (index2 < size2) {
                while (sum2[index2] == sum2[index2 - 1]) {
                    index2 += 1; cnt2 += 1;
                    if (index2 >= size2) break;
                }
            }
            counter += cnt1 * cnt2;
        }
    }

    printf("%lld\n", counter);

    return 0;
}