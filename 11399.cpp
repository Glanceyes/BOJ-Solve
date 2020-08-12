#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, sum, answer;
vector<int> sp;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        sp.push_back(input);
    }

    sort(sp.begin(), sp.end());

    for (int i = 0; i < n; i += 1) {
        sum += sp[i];
        answer += sum;
    }

    printf("%d\n", answer);

    return 0;
}