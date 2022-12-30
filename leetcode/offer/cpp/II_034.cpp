#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        int hash[26] = {};
        for (int i = 0; i < 26; i++) hash[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            if (!valid(words[i], words[i + 1], hash)) return false;
        }
        return true;
    }

private:
    bool valid(string &s, string &t, const int *hash) {
        for (int i = 0, j = 0; i < s.size() && j < t.size();) {
            char a = s[i], b = t[j];
            if (a == b) i++, j++;
            else if (hash[a - 'a'] > hash[b - 'a']) return false;
            else if (hash[a - 'a'] < hash[b - 'a']) return true;
        }
        return s.size() <= t.size();
    }
};