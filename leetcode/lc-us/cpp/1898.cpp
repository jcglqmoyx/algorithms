#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(string &s, string &p, int k, vector<int> &removable) {
        bool idx[100010];
        memset(idx, 0, sizeof idx);
        int cnt = 0;
        int index = 0;
        for (int i = 0; i < k; i++) idx[removable[i]] = true;
        for (int i = 0; i < s.length(); i++) {
            if (idx[i]) continue;
            if (cnt == p.length()) return true;
            if (s[i] == p[index]) cnt++, index++;
            if (index == p.length()) break;
        }
        return cnt == p.length();
    }

public:
    int maximumRemovals(string s, string p, vector<int> &removable) {
        int l = 0, r = removable.size();
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(s, p, mid, removable)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};