#include <cstdio>
using namespace std;

int main() {
    bool flag = true;
    char c; int cnt = 0;
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            flag = true;
        }
        else if (flag){
            cnt += 1; flag = false;
        }
    }
    printf("%d\n", cnt);
    return 0;
}