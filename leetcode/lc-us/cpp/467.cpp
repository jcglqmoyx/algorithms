#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> cnt;
        int n = (int) p.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && (p[j] == p[j - 1] + 1 || p[j - 1] == 'z' && p[j] == 'a')) j++;
            while (i < j) cnt[p[i]] = max(cnt[p[i]], j - i), i++;
        }
        int res = 0;
        for (auto[k, v]: cnt) res += v;
        return res;
    }
};