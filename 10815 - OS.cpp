#include <cstdio>
using namespace std;

#define MAX_NUM 500000

int n, m;
int num[MAX_NUM];
int sorted_num[MAX_NUM];

void merge_sort(int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    int index = start;
    int first = start, second = mid + 1;

    while (first <= mid && second <= end) {
        if (num[first] < num[second]) {
            sorted_num[index] = num[first];
            first += 1;
        }
        else {
            sorted_num[index] = num[second];
            second += 1;
        }
        index += 1;
    }


    while (first <= mid) {
        sorted_num[index] = num[first];
        index += 1; first += 1;
    }
    while (second <= end) {
        sorted_num[index] = num[second];
        index += 1; second += 1;
    }

    for (int i = start; i <= end; i += 1) {
        num[i] = sorted_num[i];
    }
}

bool binary_search(int start, int end, int value) {
    int mid = start + (end - start) / 2;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (num[mid] < value) {
            start = mid + 1;
        }
        else if (num[mid] > value) {
            end = mid - 1;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }

    merge_sort(0, n - 1);

    scanf("%d", &m);
    
    for (int i = 0; i < m; i += 1) {
        int temp; scanf("%d", &temp);
        if (binary_search(0, n - 1, temp)) {
            printf("1 ");
        }
        else {
            printf("0 ");
        }
    }
}
