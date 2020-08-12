#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s, b;
bool p[1000001];

int main() {
    cin >> s >> b;

    stack<int> ss, sb;
    int b_len = (int)b.length();

    if (b_len == 1) {
        for (int i = 0; i < (int)s.size(); i += 1) {
            if (s[i] == b[0]) {
                p[i] = true;
            }
        }
    }
    else {
        for (int i = 0; i < (int)s.size(); i += 1) {
            // 새로운 폭발 문자열의 시작인 경우
            if (s[i] == b[0]) {
                ss.push(i); sb.push(0);
            }
            else {
                // 기존 폭발 문자열의 일부인 경우
                if (!ss.empty() && !sb.empty()) {
                    int temp = sb.top() + 1;
                    if (b[temp] == s[i]) {
                        ss.push(i); sb.push(temp);
                        if (sb.top() == b_len - 1) {
                            for (int j = 0; j < b_len; j += 1) {
                                p[ss.top()] = true;
                                ss.pop(); sb.pop();
                            }
                        }
                    }
                    else {
                        while (!ss.empty() && !sb.empty()) {
                            ss.pop(); sb.pop();
                        }
                    }
                }
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < (int)s.size(); i += 1){
        if (p[i]) continue;
        printf("%c", s[i]); flag = false;
    }
    if (flag) {
        printf("FRULA\n");
    }

    return 0;
}