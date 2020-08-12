#include <cstdio>
using namespace std;

long long n;
int main() {
    scanf("%lld", &n);
    if (n % 7 == 2 || n % 7 == 0) printf("CY\n");
    else printf("SK\n");
    return 0;
}