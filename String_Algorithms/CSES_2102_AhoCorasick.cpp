/**
 * Problem: Finding Patterns (CSES 2102)
 * Link: https://cses.fi/problemset/task/2102
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// --- Optimal Solution (Aho-Corasick Algorithm) ---
// Time Complexity: O(N + ΣM + Matches)
// Space Complexity: O(ΣM * Alphabet)
struct AhoCorasick {
    struct Node {
        int next[26];
        int fail = 0;
        bool isEnd = false;
        Node() { for(int i=0; i<26; i++) next[i] = 0; }
    };
    vector<Node> trie;
    AhoCorasick() { trie.emplace_back(); }

    void insert(string& s) {
        int cur = 0;
        for (char c : s) {
            if (!trie[cur].next[c-'a']) {
                trie[cur].next[c-'a'] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].next[c-'a'];
        }
        trie[cur].isEnd = true;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (trie[0].next[i]) q.push(trie[0].next[i]);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                if (trie[u].next[i]) {
                    trie[trie[u].next[i]].fail = trie[trie[u].fail].next[i];
                    q.push(trie[u].next[i]);
                } else {
                    trie[u].next[i] = trie[trie[u].fail].next[i];
                }
            }
        }
    }
};

int main() {
    return 0;
}












