#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int children[2] = { -1, -1 };
    bool valid = false;
};

int n, ans;
vector<Node> trie;

int make_node() {
    Node new_node;
    trie.push_back(new_node);
    return (int)trie.size() - 1;
}

void add_node(int node, int v, int mv) {
    if (mv == -1) {
        trie[node].valid = true; return;
    }
    int c = (v >> mv) & 1;
    if (trie[node].children[c] == -1) {
        int next = make_node();
        trie[node].children[c] = next;
    }
    int child = trie[node].children[c];
    add_node(child, v, mv - 1);
}

int find_node(int node, int v, int mv) {
    if (mv == -1) {
        return 0;
    }
    int c = (v >> mv) & 1;
    c = 1 - c;
    if (trie[node].children[c] == -1) {
        c = 1 - c;
    }
    if (trie[node].children[c] == -1) {
        return 0;
    }
    int next = 0, child = trie[node].children[c];
    if (c == 1) next = 1 << mv;
    return next | find_node(child, v, mv - 1);
}

int main() {
    scanf("%d", &n);

    Node root;
    trie.push_back(root);
    for (int i = 0; i < n; i += 1) {
        int input; scanf("%d", &input);
        add_node(0, input, 31);
        int temp = (find_node(0, input, 31) ^ input);
        if (ans < temp) ans = temp;
    }
    printf("%d\n", ans);

    return 0;
}