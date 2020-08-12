#include <cstdio>
using namespace std;

int sum, num, temp;
char c;
bool flag;

int main() {
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            num = (num * 10) + (int)(c - '0');
        }
        else {
            temp += num;
            num = 0;
            if (c == '-') {
                if (!flag) {
                    sum += temp;
                    flag = true;
                }
                else {
                    sum -= temp;
                }
                temp = 0;
            }
        }
    }
    temp += num; 
    if (!flag) {
        sum += temp;
    }
    else {
        sum -= temp;
    }
    printf("%d\n", sum);
    
    return 0;
}