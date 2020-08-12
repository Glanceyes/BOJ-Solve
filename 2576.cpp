#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int num[7], sum;
vector<int> odd;

int main() {
    for (int i = 0; i < 7; i += 1) {
        scanf("%d", &num[i]);
        if (num[i] % 2) {
            odd.push_back(num[i]);
        }
    }

    if (odd.size() > 0) {
        for (unsigned int i = 0; i < odd.size(); i += 1) {
            sum += odd[i];
        }

        sort(odd.begin(), odd.end());

        printf("%d\n", sum);
        printf("%d\n", odd[0]);
    }
    else {
        printf("-1\n");
    }

    return 0;
}