#include <cstdio>
#include <vector>

using namespace std;

#define MAX 4000001

int n;
bool erase[MAX];
vector<int> prime;

int main() {
    int left, right, sum, counter;
    left = right = sum = counter = 0;
    scanf("%d", &n);

    for (int i = 2; i <= n; i += 1) {
        if (!erase[i]) {
            erase[i] = true;
            prime.push_back(i);
        }
        for (int j = i * 2; j <= n; j += i) {
            erase[j] = true;
        }
    }
    
    int primesize = prime.size();
    if (primesize > 0) sum = prime[0];

    while (left <= right && right < primesize) {
        if (sum <= n) {
            if (sum == n) {
                counter += 1;
            }
            if (right == primesize - 1) break;
            right += 1;
            sum += prime[right];
        }
        else {
            sum -= prime[left];
            if (left == primesize - 1) break;
            left += 1;
            if (left > right && left < primesize) {
                right = left;
                sum = prime[right];
            }
        }
    }

    printf("%d\n", counter);

    return 0;
}