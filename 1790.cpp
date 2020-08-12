#include <cstdio>
#include <tuple>
#include <string>
using namespace std;

int n, k;

int digit(int x) {
    int cnt = 0;
    do {
        x /= 10; cnt += 1;
    } while (x);
    return cnt;
}

pair<int, int> num_length(int x) {
    int cnt = digit(x);
    int mul = 9, dec = 1;
    pair<int, int> result;
    result.first = 0;
    for (int i = 1; i < cnt; i += 1) {
        result.first += i * mul;
        mul *= 10; dec *= 10;
    }
    result.first += (x - dec) * cnt;
    result.second += result.first + cnt;
    return result;
}

void find(int left, int right) {
    if (left > right) return;

    int mid = left + (right - left) / 2;
    pair<int, int> idx;
    idx = num_length(mid);
    if (idx.first < k && k <= idx.second) {
        string ans = to_string(mid);
        printf("%c\n", ans[k - (idx.first + 1)]);
        return;
    }
    
    if (k <= idx.first) {
        find(left, mid - 1);
    }
    else if (k > idx.second) {
        find(mid + 1, right);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &k);

    pair<int, int> t;

    t = num_length(n);
    
    if (t.second < k) {
        printf("-1\n"); return 0;
    }

    find(1, n);

    return 0;
}