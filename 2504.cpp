#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int sum;
string s;

bool is_right() {
    stack<char> st;
    for (int i = 0; i < (int)s.size(); i += 1) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        }
        else  {
            if (!st.empty()) {
                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
            }
            else { return false; }
        }
    }
    return st.empty();
}

int main() {
    cin >> s;

    if (is_right()) {
        string ns;
        vector<char> sc;
        vector<int> si;
        for (int i = 0; i < (int)s.size(); i += 1) {
            if (i == 0) {
                ns += s[i]; continue;
            }
            else {
                if ((s[i - 1] == ')' || s[i - 1] == ']') &&
                    (s[i] == '(' || s[i] == '[')) {
                    ns += '+';
                }
                ns += s[i];
            }
        }
        for (int i = 0; i < (int)ns.size(); i += 1) {
            if (ns[i] == '(' || ns[i] == '[' || ns[i] == '+') {
                sc.push_back(ns[i]);
            }
            else if (ns[i] == ')' || ns[i] == ']') {
                int temp1 = 0, temp2 = 0;
                while (sc.back() == '+') {
                    temp1 = si.back(); si.pop_back();
                    temp2 = si.back(); si.pop_back();
                    si.push_back(temp1 + temp2); sc.pop_back();
                }
                if (sc.back() == '(') {
                    if (ns[i - 1] == '(') {
                        si.push_back(2);
                    }
                    else {
                        temp1 = si.back(); si.pop_back();
                        si.push_back(2 * temp1);
                    }
                }
                else if (sc.back() == '[') {
                    if (ns[i - 1] == '[') {
                        si.push_back(3);
                    }
                    else {
                        temp1 = si.back(); si.pop_back();
                        si.push_back(3 * temp1);
                    }
                }
                sc.pop_back();
            }
        }
        int sum = 0;
        while (!si.empty()) {
            sum += si.back(); si.pop_back();
        }
        printf("%d\n", sum);
    }
    else {
        printf("0\n");
    }
    

    return 0;
}