#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
    int children[26];
    int fail;
    bool valid;
    Node() {
        for (int i = 0; i < 26; i += 1) {
            children[i] = -1;
        }
        valid = false; 
        fail = -1;
    }
};

vector<Node> trie;
int make_node() {
    Node x; 
    trie.push_back(x);
    return (int)trie.size() - 1;
}

void add(int node, string& s, int index) {
    if (index == (int)s.size()) {
        trie[node].valid = true;
        return;
    }
    int c = s[index] - 'a';
    if (trie[node].children[c] == -1) {
        int next = make_node();
        trie[node].children[c] = next;
    }
    add(trie[node].children[c], s, index + 1);
}

int main() {
    int n; cin >> n;
    int root = make_node();
    for (int i = 0; i < n; i += 1) {
        string s; cin >> s;
        add(root, s, 0);
    }

    queue<int> q;
    trie[root].fail = root;
    q.push(root);

    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (int i = 0; i < 26; i += 1) {
            int next = trie[current].children[i];
            if (next == -1) continue;
            if (current == root) {
                trie[next].fail = root; // 길이가 1인 prefix
            }
            else {
                int x = trie[current].fail;
                while (x != root && trie[x].children[i] == -1) {
                    x = trie[x].fail;
                }
                if (trie[x].children[i] != -1) {
                    x = trie[x].children[i];
                }
                trie[next].fail = x;
            }
            int fail = trie[next].fail;
            trie[next].valid |= trie[fail].valid;
            q.push(next);
        }
    }

    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        int node = root; 
        bool flag = false;
        for (int i = 0; i < (int)s.size(); i += 1) {
            int c = s[i] - 'a';
            while (node != root && trie[node].children[c] == -1) {
                node = trie[node].fail;
            }
            if (trie[node].children[c] != -1) {
                node = trie[node].children[c];
            }
            if (trie[node].valid) {
                flag = true;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}