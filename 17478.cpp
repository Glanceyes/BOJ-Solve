#include <cstdio>
#include <iostream>
using namespace std;

int n;

void repeat(int finish) {
    for (int i = 0; i < finish; i += 1) {
        printf("____");
    }
}

void go(int idx) {
    repeat(idx);
    printf("\"����Լ��� ������?\"\n");
    repeat(idx);
    if (idx == n) {
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
    }
    else {
        printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
        repeat(idx);
        printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
        repeat(idx);
        printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
        go(idx + 1);
    }
    repeat(idx);
    printf("��� �亯�Ͽ���.\n");
    return;
}

int main() {
    scanf("%d", &n);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    go(0);
    return 0;
}