#include <bits/stdc++.h>

using namespace std;

class Solution {
    int calc(string &s, char c) {
        unordered_set<char> set;
        int n = (int) s.size();
        int l = 0, r = n - 1;
        while (l < r - 1 && s[l] != c) l++;
        while (r > l + 1 && s[r] != c) r--;
        if (r - l <= 1) return 0;
        for (int i = l + 1; i < r; i++) set.insert(s[i]);
        return (int) set.size();
    }

public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            cnt += calc(s, c);
        }
        return cnt;
    }
};