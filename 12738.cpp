#include <cstdio>
#include <map>
using namespace std;

#define l_max 1000000

int n, max_length;
int num[l_max];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        scanf("%d", &num[i]);
    }

    map<int, int> m;
    m[num[0]] = 1; max_length = 1;
    
    for (int i = 1; i < n; i += 1) {
        auto iter = m.lower_bound(num[i]);
        if (iter != m.end()) {
            if (m[iter->first] > m[num[i]]) {
                m[num[i]] = m[iter->first];
                m.erase(iter->first);
            }
        }
        else {
            max_length += 1;
            m[num[i]] = max_length;
        }

    }
    printf("%d\n", max_length);

    return 0;
}