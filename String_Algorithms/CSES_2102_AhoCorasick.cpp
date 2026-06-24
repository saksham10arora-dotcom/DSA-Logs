```cpp
// Aho Corasick, https://cses.fi/problemset/task/2102, 
// Aho-Corasick string matching algorithm implementation.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach with O(n*m*k) complexity
// where n is the length of the text, m is the number of patterns, and k is the maximum length of a pattern
void bruteForce(const std::string& text, const std::vector<std::string>& patterns) {
    for (const auto& pattern : patterns) {
        for (int i = 0; i <= text.size() - pattern.size(); ++i) {
            if (text.substr(i, pattern.size()) == pattern) {
                std::cout << pattern << " found at position " << i << std::endl;
            }
        }
    }
}

// Aho-Corasick node structure
struct Node {
    int next[26];
    int link;
    int go[26];
    bool leaf;
    int p;
    char pch;
    Node() : link(0), leaf(false), p(0), pch('\0') {
        for (int i = 0; i < 26; ++i) {
            next[i] = 0;
            go[i] = 0;
        }
    }
};

// Optimal solution with O(n + m + k) complexity
// where n is the length of the text, m is the number of patterns, and k is the maximum length of a pattern
void ahoCorasick(const std::string& text, const std::vector<std::string>& patterns) {
    std::vector<Node> t(1);
    int n = 0;
    for (const auto& pattern : patterns) {
        int v = 0;
        for (char c : pattern) {
            int cidx = c - 'a';
            if (t[v].next[cidx] == 0) {
                t[v].next[cidx] = ++n;
                t.emplace_back();
            }
            v = t[v].next[cidx];
        }
        t[v].leaf = true;
        t[v].p = pattern.size();
        t[v].pch = pattern.back();
    }

    // Build suffix links
    std::vector<int> q(1, 0);
    for (int i = 0; i < q.size(); ++i) {
        int v = q[i];
        for (int c = 0; c < 26; ++c) {
            if (t[v].next[c]) {
                int u = t[v].next[c];
                q.push_back(u);
                if (v == 0) {
                    t[u].link = 0;
                } else {
                    int w = t[v].link;
                    while (w && !t[w].next[c]) {
                        w = t[w].link;
                    }
                    if (w) {
                        t[u].link = t[w].next[c];
                    } else {
                        t[u].link = 0;
                    }
                }
            }
        }
    }

    // Build go array
    for (int v = 1; v <= n; ++v) {
        for (int c = 0; c < 26; ++c) {
            if (t[v].next[c]) {
                t[v].go[c] = t[v].next[c];
            } else {
                int w = v;
                while (w && !t[w].next[c]) {
                    w = t[w].link;
                }
                if (w) {
                    t[v].go[c] = t[w].next[c];
                } else {
                    t[v].go[c] = 0;
                }
            }
        }
    }

    // Search for patterns in the text
    int v = 0;
    for (int i = 0; i < text.size(); ++i) {
        int cidx = text[i] - 'a';
        v = t[v].go[cidx];
        int u = v;
        while (u) {
            if (t[u].leaf) {
                std::cout << "Pattern found at position " << i - t[u].p + 1 << std::endl;
            }
            u = t[u].link;
        }
    }
}

int main() {
    std::string text = "abcabc";
    std::vector<std::string> patterns = {"a", "ab", "abc"};
    std::cout << "Brute force approach:" << std::endl;
    bruteForce(text, patterns);
    std::cout << "Aho-Corasick approach:" << std::endl;
    ahoCorasick(text, patterns);

    text = "banana";
    patterns = {"ana", "na", "an"};
    std::cout << "Brute force approach:" << std::endl;
    bruteForce(text, patterns);
    std::cout << "Aho-Corasick approach:" << std::endl;
    ahoCorasick(text, patterns);

    text = "abxabcabcaby";
    patterns = {"ab", "abc", "aby"};
    std::cout << "Brute force approach:" << std::endl;
    bruteForce(text, patterns);
    std::cout << "Aho-Corasick approach:" << std::endl;
    ahoCorasick(text, patterns);

    return 0;
}
```