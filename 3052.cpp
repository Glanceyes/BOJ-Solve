#include <cstdio>
using namespace std;

int answer;
bool left[42];

int main() {
    for (int i = 0; i < 10; i += 1) {
        int input; scanf("%d", &input);
        int temp = input % 42;
        if (!left[temp]) {
            answer += 1;
            left[temp] = true;
        }
    }
    printf("%d\n", answer);
}