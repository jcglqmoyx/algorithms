#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> cnt(26);
        for (char c: s) cnt[c - 'a']++;
        sort(cnt.begin(), cnt.end(), greater<>());
        while (!cnt.back()) cnt.pop_back();
        int res = 0;
        for (int i = 0, j = 0; i < cnt.size(); i++, j++) {
            if (j < 9) res += cnt[i];
            else if (j < 18) res += cnt[i] << 1;
            else res += cnt[i] * 3;
        }
        return res;
    }
};