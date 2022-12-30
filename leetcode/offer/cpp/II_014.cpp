#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> m1, m2;
        for (char c: s1) m1[c]++;
        for (int i = 0; i < s1.size() - 1; i++) m2[s2[i]]++;
        for (int i = 0, j = (int) s1.size() - 1; j < s2.size(); j++) {
            m2[s2[j]]++;
            if (equals(m1, m2)) return true;
            m2[s2[i]]--;
            if (m2[s2[i]] == 0) m2.erase(s2[i]);
            i++;
        }
        return false;
    }

private:
    bool equals(unordered_map<char, int> &m, unordered_map<char, int> &n) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (!m.count(c) && !n.count(c)) continue;
            else if (!m.count(c) || !n.count(c)) return false;
            if (m[c] != n[c]) return false;
        }
        return true;
    }
};