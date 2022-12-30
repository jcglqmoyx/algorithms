#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int respace(vector<string> &dictionary, string sentence) {
        int n = (int) sentence.size();
        unordered_set<string> s;
        for (string &word: dictionary) s.insert(word);
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) f[i] = i;
        for (int i = 1; i <= n; i++) {
            for (int len = i; len >= 1; len--) {
                if (s.count(sentence.substr(i - len, len))) f[i] = min(f[i], f[i - len]);
                f[i] = min(f[i], f[i - len] + len);
            }
        }
        return f[n];
    }
};