#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000

int n, m;
int a[MAX + 1];
int b[MAX + 1];

long long t;
vector<long long> sumA, sumB;

int main() {
    scanf("%lld", &t);

    scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i += 1) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 0; j < n - i + 1; j += 1) {
            long long temp = 0;
            for (int k = 0; k < i; k += 1) {
                temp += a[j + k];
            }
            sumA.push_back(temp);
        }
    }

    for (int i = 1; i <= m; i += 1) {
        for (int j = 0; j < m - i + 1; j += 1) {
            long long temp = 0;
            for (int k = 0; k < i; k += 1) {
                temp += b[j + k];
            }
            sumB.push_back(temp);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());
    reverse(sumB.begin(), sumB.end());

    long long sumAsize = (long long)sumA.size();
    long long sumBsize = (long long)sumB.size();
    long long counter = 0;

    long long indexA, indexB;
    indexA = indexB = 0;

    while (indexA < sumAsize && indexB < sumBsize) {
        if (sumA[indexA] + sumB[indexB] < t) {
            indexA += 1;
        }
        else if (sumA[indexA] + sumB[indexB] > t) {
            indexB += 1;
        }
        else {
            long long cnt1, cnt2;
            cnt1 = cnt2 = 1;
            indexA += 1; indexB += 1;
            if (indexA < sumAsize) {
                while (sumA[indexA] == sumA[indexA - 1]) {
                    cnt1 += 1; indexA += 1;
                    if (indexA >= sumAsize) break;
                }
            }
            if (indexB < sumBsize) {
                while (sumB[indexB] == sumB[indexB - 1]) {
                    cnt2 += 1; indexB += 1;
                    if (indexB >= sumBsize) break;
                }
            }
            counter += cnt1 * cnt2;
        }
    }

    printf("%lld\n", counter);

    return 0;
}