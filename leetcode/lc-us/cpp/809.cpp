#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<pair<char, int>> map;

    bool valid(string &s, string &w) {
        int m = (int) w.size();
        if (m > n) return false;
        vector<pair<char, int>> groups;
        int len = 1;
        for (int i = 0; i < m - 1; i++) {
            if (w[i] == w[i + 1]) {
                len++;
                if (i == m - 2) groups.emplace_back(w[i], len);
            } else {
                groups.emplace_back(w[i], len);
                if (i == m - 2) groups.emplace_back(w[m - 1], 1);
                len = 1;
            }
        }
        int len1 = (int) map.size(), len2 = (int) groups.size();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++) {
            if (map[i].first != groups[i].first) return false;
            if (map[i].second < groups[i].second || map[i].second > groups[i].second && map[i].second < 3) return false;
        }
        return true;
    }

public:
    int expressiveWords(string s, vector<string> &words) {
        n = (int) s.size();
        int len = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                len++;
                if (i == n - 2) map.emplace_back(s[i], len);
            } else {
                map.emplace_back(s[i], len);
                if (i == n - 2) map.emplace_back(s[n - 1], 1);
                len = 1;
            }
        }
        int cnt = 0;
        for (string &w: words) {
            if (valid(s, w)) cnt++;
        }
        return cnt;
    }
};