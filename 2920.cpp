#include <cstdio>
using namespace std;

int prev;
int ascend, descend;

int main() {
    ascend = descend = 1;
    for (int i = 0; i < 8; i += 1) {
        int temp; scanf("%d", &temp);

        if (i == 0) {
            prev = temp; continue;
        }
        
        if (prev < temp) {
            ascend *= 1; descend *= 0;
        }
        else {
            ascend *= 0; descend *= 1;
        }
        prev = temp;
    }

    if (ascend) {
        printf("ascending\n");
    }
    else if (descend) {
        printf("descending\n");
    }
    else {
        printf("mixed\n");
    }

    return 0;
}