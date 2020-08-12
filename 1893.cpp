#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t;
string a, w, s;
vector<int> find(string p) {
    int p_size = (int)p.size();
    vector<int> fail(p_size);
    int j = 0; fail[0] = 0;
    for (int i = 1; i < p_size; i += 1) {
        while (j > 0 && p[i] != p[j]) {
            j = fail[j - 1];
        }
        if (p[i] == p[j]) {
            fail[i] = j + 1; j += 1;
        }
        else {
            fail[i] = 0;
        }
    }
    return fail;
}

bool kmp(string s, string p) {
    int s_size = (int)s.size();
    int p_size = (int)p.size();
    int answer = 0;
    vector<int> fail = find(p);
    for (int i = 0, j = 0; i < s_size; i += 1) {
        while (j > 0 && s[i] != p[j]) {
            j = fail[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == p_size - 1) {
                answer += 1; j = fail[j];
            }
            else {
                j += 1;
            }
        }
    }
    return (answer == 1) ? true : false;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> w >> s;
        int w_size = (int)w.size();
        int a_size = (int)a.size();
        vector<int> p(w_size), shift;
        for (int i = 0; i < w_size; i += 1) {
            for (int j = 0; j < a_size; j += 1) {
                if (w[i] == a[j]) {
                    p[i] = j; continue;
                }
            }
        }
        
        for (int i = 1; i <= a_size; i += 1) {
            for (int j = 0; j < w_size; j += 1) {
                int k = p[j] + 1;
                if (k >= a_size) {
                    k = 0;
                }
                p[j] = k; w[j] = a[k];
            }
            if (kmp(s, w)) {
                shift.push_back(i % a_size);
            }
        }
        int shift_size = (int)shift.size();
        if (shift_size) {
            sort(shift.begin(), shift.end());
            if (shift_size > 1) {
                printf("ambiguous: ");
            }
            else {
                printf("unique: ");
            }
            for (int i = 0; i < shift_size; i += 1) {
                printf("%d ", shift[i]);
            }
        }
        else {
            printf("no solution");
        }
        printf("\n");
    }

    return 0;
}