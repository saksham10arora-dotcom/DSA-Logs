/**
 * Problem: String Matching (CSES 1753)
 * Link: https://cses.fi/problemset/task/1753
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Optimal Solution (KMP Algorithm) ---
// Time Complexity: O(N + M)
// Space Complexity: O(M)
vector<int> buildLPS(string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}

int kmpSearch(string& txt, string& pat) {
    int n = txt.size(), m = pat.size();
    if (m == 0) return 0;
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0, count = 0;
    while (i < n) {
        if (txt[i] == pat[j]) { i++; j++; }
        if (j == m) { count++; j = lps[j-1]; }
        else if (i < n && txt[i] != pat[j]) {
            if (j) j = lps[j-1];
            else i++;
        }
    }
    return count;
}

int main() {
    // string s, p; cin >> s >> p;
    // cout << kmpSearch(s, p) << endl;
    return 0;
}














