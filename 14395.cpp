#include <cstdio>
#include <queue>
#include <string>
#include <map>
using namespace std;

#define max 1000000000

long long s, t;
string ss;
map<long long, pair<long long, char>> m;
char opt[4] = { '*', '+', '-', '/' };

bool find() {
    queue<long long> q; q.push(s);
    m[s].first = -1; m[s].second = '\0';

    while (!q.empty()) {
        queue<long long> next_q;
        while (!q.empty()) {
            long long x = q.front(), tx = 0; q.pop();
            if (x == t) {
                while (!q.empty()) { q.pop(); }
                long long temp = x;
                while (temp != s) {
                    ss += m[temp].second;
                    temp = m[temp].first;
                }
                return true;
            }
            
            for (int i = 0; i < 4; i += 1) {
                switch (opt[i]) {
                case '*': tx = x * x; break;
                case '+': tx = x + x; break;
                case '-': tx = x - x; break;
                case '/': if (x) { tx = x / x; }; break;
                }
                if (tx > max || m.find(tx) != m.end()) { continue; }
                m[tx].first = x; m[tx].second = opt[i]; 
                next_q.push(tx);
            }
        }
        q = next_q;
    }
    return false;
}

int main() {
    scanf("%lld %lld", &s, &t);
    if (s == t) {
        printf("0\n");
    }
    else if (find()){
        for (int i = ss.length() - 1; i >= 0; i -= 1) {
            printf("%c", ss[i]);
        }
        printf("\n");
    }
    else {
        printf("-1\n");
    }

    return 0;
}