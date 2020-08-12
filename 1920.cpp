#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num;
vector<int> v;

void binary_search(int start, int mid, int end) {
    if (start > end) {
        printf("0\n");
        return;
    }

    if (v[mid] < num) {
        start = mid + 1;
        mid = end + (start - end) / 2;
        binary_search(start, mid, end);
    }
    else if (v[mid] == num) {
        printf("1\n"); return;
    }
    else {
        end = mid - 1;
        mid = end + (start - end) / 2;
        binary_search(start, mid, end);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1) {
        scanf("%d", &num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    scanf("%d", &m);
    for (int i = 1; i <= m; i += 1) {
        scanf("%d", &num);
        binary_search(0, (n - 1) / 2, n - 1);
    }

    return 0;
}