#include <cstdio>
using namespace std;

long long a, b, c, x;

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    
    if (c - b <= 0) {
        printf("-1\n");
    }
    else {
        x = a / (c - b) + 1; 
        if (x <= 0) {
            printf("-1\n");
        }
        else {
            printf("%lld\n", x);
        }
    }

    return 0;
}