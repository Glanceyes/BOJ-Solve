#include <cstdio>
using namespace std;

int n, cnt;

int main() {
    scanf("%d\n", &n);

    while (n--) {
        bool p[26], flag = true;
        for (int i = 0; i < 26; i += 1) {
            p[i] = false;
        }
        char c, prev = getchar(); 
        p[prev - 'a'] = true;
        while ((c = getchar()) != '\n') {
            if (c != prev) {
                if (!p[c - 'a']) {
                    p[c - 'a'] = true;
                }
                else {
                    flag = false;
                }
            }
            prev = c;
        }
        if (flag) { cnt += 1; }
    }

    printf("%d\n", cnt);

    return 0;
}