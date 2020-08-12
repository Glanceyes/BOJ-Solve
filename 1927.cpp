#include <cstdio>
#include <climits>
using namespace std;

int n, num;
int heap[100001];

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int pop() {
    if (num <= 0) {
        return 0;
    }
    int ans = heap[1];
    heap[1] = heap[num];
    heap[num--] = INT_MAX;
    for (int i = 1; i * 2 <= num;) {
        if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1]) {
            break;
        }
        else if (heap[i * 2] < heap[i * 2 + 1]) {
            swap(heap[i], heap[i * 2]);
            i = i * 2;
        }
        else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }
    return ans;
}

void push(int x) {
    heap[++num] = x;
    for (int i = num; i > 1; i /= 2) {
        if (heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
        }
        else {
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i += 1) {
        int x; scanf("%d", &x);
        if (x == 0) {
            printf("%d\n", pop());
        }
        else {
            push(x);
        }
    }

    return 0;
}