//https://www.acmicpc.net/board/view/38424
//질문에 답변 해주기 위한 잘못된 풀이 코드

//첫번째 코드
#include <cstdio>
#include <iostream>
using namespace std;
int N;
int arr[1001] = { 0, };
int dp[1001] = { 0, };
int mmax = 0;
int main() {
    int i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1;
        for (j = 1; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                if (dp[i] > mmax)    //dp[i]의 값이 바뀔때마다 최댓값과 비교, 갱신
                    mmax = dp[i];
            }
        }
    }
    printf("%d", mmax);
}