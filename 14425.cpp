#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, ans;
struct Node {
    int children[26];
    bool valid;
    Node() {
        for (int i = 0; i < 26; i += 1) {
            children[i] = -1;
        }
        valid = false;
    }
};

vector<Node> trie;

int make_node() {
    Node new_node;
    trie.push_back(new_node);
    return trie.size() - 1;
}

void add(int node, string& s, int idx) {
    // 비교 문자열의 모든 문자를 다 비교했을 경우
    if (idx == s.length()) {
        trie[node].valid = true; return;
    }
    int c = s[idx] - 'a';
    // 현재 보고 있는 문자가 자식으로 있지 않은 경우
    if (trie[node].children[c] == -1) {
        int rear = make_node();
        trie[node].children[c] = rear;
    }
    int child = trie[node].children[c];
    add(child, s, idx + 1);
}

bool search(int node, string& s, int idx) {
    // 리프 노드 끝까지 도달해도 나오지 않는 경우
    if (node == -1) {
        return false;
    }
    if (idx == s.length()) {
        return trie[node].valid;
    }
    int c = s[idx] - 'a';
    int child = trie[node].children[c];
    return search(child, s, idx + 1);
}

int main() {
    cin >> n >> m;
    make_node();
    for (int i = 0; i < n; i += 1) {
        string s; cin >> s;
        add(0, s, 0);
    }
    for (int j = 0; j < m; j += 1) {
        string s; cin >> s;
        if (search(0, s, 0)) {
            ans += 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}