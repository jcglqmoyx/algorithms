#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        int n = (int) words.size();
        int s[n + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (is_vowel(words[i - 1].front()) && is_vowel(words[i - 1].back()));
        }
        int m = (int) queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = s[queries[i][1] + 1] - s[queries[i][0]];
        }
        return res;
    }
};