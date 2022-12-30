#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> cnt, hash;
        for (char c: p) cnt[c]++;
        for (int i = 0, j = 0; j < s.size(); j++) {
            hash[s[j]]++;
            while (i <= j && (!cnt.count(s[i]) || hash[s[i]] > cnt[s[i]])) {
                hash[s[i]]--;
                if (hash[s[i]] == 0) hash.erase(s[i]);
                i++;
            }
            if (hash == cnt) res.push_back(i);
        }
        return res;
    }
};