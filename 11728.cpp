#include <cstdio>
#include <vector>
using namespace std;

int n, m;

void merge_sort(vector<int>& v, int start, int end) {
    if (start == end) return;
    int mid = start + (end - start) / 2;
    
    merge_sort(v, start, mid);
    merge_sort(v, mid + 1, end);

    vector<int> temp;

    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            temp.push_back(v[i]); i += 1;
        }
        else {
            temp.push_back(v[j]); j += 1;
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
    scanf("%d %d", &n, &m);
    vector<int> num(n + m);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }
    
    for (int j = 0; j < m; j += 1) {
        scanf("%d", &num[n + j]);
    }

    merge_sort(num, 0, n + m - 1);
    for (int i = 0; i < n + m; i += 1) {
        printf("%d ", num[i]);
    }

    return 0;
}