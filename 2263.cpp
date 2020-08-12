#include <cstdio>
#include <vector>
using namespace std;

typedef struct TREE {
    int value = 0;
    TREE* left = NULL;
    TREE* right = NULL;
}Tree;

int n, idx;
TREE root;
vector<int> inorder, postorder;
int position[100001];

void preorder(Tree* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    preorder(node->left);
    preorder(node->right);

    return;
}

void make_tree(int start, int end, Tree* parent) {
    parent->value = postorder[idx];
    int pivot = position[postorder[idx]];

    if (idx - 1 >= 0 && pivot + 1 <= end) {
        parent->right = new Tree; idx -= 1;
        make_tree(pivot + 1, end, parent->right);
    }

    if (idx - 1 >= 0 && pivot - 1 >= start) {
        parent->left = new Tree; idx -= 1;
        make_tree(start, pivot - 1, parent->left);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        position[input] = i;
        inorder.push_back(input);
    }

    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        postorder.push_back(input);
    }

    idx = n - 1;
    make_tree(0, n - 1, &root);

    preorder(&root);
    printf("\n");

    return 0;
}