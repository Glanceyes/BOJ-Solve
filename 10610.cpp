#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int three_m, zero_num;
char c;
string s;

int main() {
    while ((c = getchar()) != '\n') {
        if (c == '0') {
            zero_num += 1; continue;
        }
        three_m += (int)(c - '0');
        s.push_back(c);
    }
    if (three_m % 3 != 0 || !zero_num) {
        printf("-1\n");
        return 0;
    }

    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    for (int i = 0; i < (int)s.length(); i += 1) {
        printf("%c", s[i]);
    }
    for (int i = 0; i < zero_num; i += 1) {
        printf("0");
    }

    printf("\n");

    return 0;
}