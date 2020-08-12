#include <cstdio>
using namespace std;

int n, num = -1, answer[2];
bool b[100000][2];
bool t[100000];
bool flag[2];

int main() {
    scanf("%d\n", &n);
    
    for (int i = 0; i < 2; i += 1) {
        for (int j = 0; j < n; j += 1) {
            b[j][i] = (int)(getchar() - '0');
        }
        getchar();
    }

    for (int k = 0; k < 2; k += 1) {
        // 상태 초기화
        for (int i = 0; i < n; i += 1) {
            t[i] = b[i][0];
        }
        
        // 맨 왼쪽 스위치 눌렀을 때
        if (!k) {
            t[0] = 1 - t[0]; t[1] = 1 - t[1];
            answer[k] += 1;
        }

        for (int i = 0; i < n - 1; i += 1) {
            if (t[i] != b[i][1]) {
                for (int j = i; j < i + 3 && j < n; j += 1) {
                    t[j] = 1 - t[j];
                }
                answer[k] += 1;
            }
        }

        if (t[n - 1] == b[n - 1][1]) {
            flag[k] = true;
        }
    }

    for (int k = 0; k < 2; k += 1) {
        if (flag[k] && (answer[k] < num || num == -1)) {
            num = answer[k];
        }
    }

    printf("%d\n", num);

    return 0;
}