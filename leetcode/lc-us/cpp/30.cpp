#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int n = (int) s.size(), m = (int) words.size(), w = (int) words[0].size();
        unordered_map<string, int> tot;
        for (auto &word: words) tot[word]++;
        vector<int> res;
        for (int i = 0; i < w; i++) {
            int cnt = 0;
            unordered_map<string, int> hash;
            for (int j = i; j + w <= n; j += w) {
                string word = s.substr(j, w);
                hash[word]++;
                if (hash[word] <= tot[word]) cnt++;
                if (j >= i + m * w) {
                    string prev = s.substr(j - m * w, w);
                    hash[prev]--;
                    if (hash[prev] < tot[prev]) cnt--;
                }
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};