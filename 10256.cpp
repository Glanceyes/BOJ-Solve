#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define A 0
#define C 1
#define G 2
#define T 3

struct Node {
    int children[4];
    int prev;
    bool valid;
    Node() {
        for (int i = 0; i < 4; i += 1) {
            children[i] = -1;
        }
        prev = -1; valid = false;
    }
};

int make_node(vector<Node>& trie) {
    Node x;
    trie.push_back(x);
    return (int)trie.size() - 1;
}

void add_node(vector<Node>& trie, int node, string& s, int index) {
    if (index == (int)s.size()) {
        trie[node].valid = true;
        return;
    }
    int c = 0;
    switch (s[index]) {
    case 'A':
        c = A; break;
    case 'C':
        c = C; break;
    case 'G':
        c = G; break;
    case 'T':
        c = T; break;
    }
    if (trie[node].children[c] == -1) {
        int next_node = make_node(trie);
        trie[node].children[c] = next_node;
    }
    int child = trie[node].children[c];
    add_node(trie, child, s, index + 1);
}

int main() {
    int t; cin >> t;
    while (t--) {
        vector<Node> trie;
        int sl, ml; cin >> sl >> ml;
        string s, m; cin >> s >> m;

        int root = make_node(trie);
        add_node(trie, root, m, 0);

        for (int i = 0; i < ml; i += 1) {
            for (int j = i + 2; j <= ml; j += 1) {
                reverse(&m[i], &m[j]);
                add_node(trie, root, m, 0);
                reverse(&m[i], &m[j]);
            }
        }

        queue<int> q;
        trie[root].prev = root;
        q.push(root);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < 4; i += 1) {
                int next = trie[cur].children[i];
                if (next == -1) {
                    continue;
                }
                if (cur == root) {
                    trie[next].prev = root;
                }
                else {
                    int x = trie[cur].prev;
                    while (x != root && trie[x].children[i] == -1) {
                        x = trie[x].prev;
                    }
                    if (trie[x].children[i] != -1) {
                        x = trie[x].children[i];
                    }
                    trie[next].prev = x;
                }
                int prev = trie[next].prev;
                trie[next].valid |= trie[prev].valid;
                q.push(next);
            }
        }

        int node = root, cnt = 0;
        for (int i = 0; i < (int)s.size(); i += 1) {
            int c = 0;
            switch (s[i]) {
            case 'A':
                c = A; break;
            case 'C':
                c = C; break;
            case 'G':
                c = G; break;
            case 'T':
                c = T; break;
            }
            while (node != root && trie[node].children[c] == -1) {
                node = trie[node].prev;
            }
            if (trie[node].children[c] != -1) {
                node = trie[node].children[c];
            }
            if (trie[node].valid) {
                cnt += 1;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}