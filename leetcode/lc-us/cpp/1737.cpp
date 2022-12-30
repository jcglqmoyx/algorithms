#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 1e8;

    int calc(vector<int> &s1, vector<int> &s2) {
        int res = INF;
        for (int i = 1; i < 26; i++) {
            int cnt = 0;
            for (int j = 0; j < i; j++) cnt += s1[j];
            for (int j = i; j < 26; j++) cnt += s2[j];
            res = min(res, cnt);
        }
        return res;
    }

public:
    int minCharacters(string a, string b) {
        vector<int> s1(36), s2(26);
        for (char c: a) s1[c - 'a']++;
        for (char c: b) s2[c - 'a']++;
        int res = INF;
        for (int i = 0; i < 26; i++) {
            res = min(res, (int) a.size() + (int) b.size() - s1[i] - s2[i]);
        }
        return min(res, min(calc(s1, s2), calc(s2, s1)));
    }
};