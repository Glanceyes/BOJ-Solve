#include <cstdio>
#include <vector>
using namespace std;

long sum(std::vector<int>& a) {
    long result = 0;
    for (int i = 0; i < (int)a.size(); i += 1) {
        result += a[i];
    }
    return result;
}