#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_subsequence(string &s, string &w) {
        int m = s.length(), n = w.length();
        int j = 0;
        for (int i = 0; i < m && j < n;) {
            while (i < m && j < n && w[j] != s[i]) i++;
            while (i < m && j < n && w[j] == s[i]) {
                j++;
                i++;
            }
        }
        return j == n;
    }

public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string res;
        int n = s.length();
        for (string &w: dictionary) {
            if (w.length() > n || w.length() < res.length()) continue;
            if (is_subsequence(s, w)) {
                if (res.empty() || w.length() > res.length() || w < res) res = w;
            }
        }
        return res;
    }
};