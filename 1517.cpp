#include <cstdio>
#include <vector>
using namespace std;

int n;
long long answer;

void merge_sort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    
    int mid = start + (end - start) / 2;

    merge_sort(v, start, mid);
    merge_sort(v, mid + 1, end);

    vector<int> temp;

    long long c = mid - start + 1;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (v[i] > v[j]) {
            temp.push_back(v[j]); j += 1;
            answer += c;
        }
        else {
            temp.push_back(v[i]); i += 1;
            c -= 1;
        }
    }
    while (i <= mid) {
        temp.push_back(v[i]); i += 1;
    }
    while (j <= end) {
        temp.push_back(v[j]); j += 1;
    }

    for (int i = start; i <= end; i += 1) {
        v[i] = temp[i - start];
    }
}

int main() {
    scanf("%d", &n);
    vector<int> num(n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }
    
    merge_sort(num, 0, n - 1);
    printf("%lld\n", answer);

    return 0;
}