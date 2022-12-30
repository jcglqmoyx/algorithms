#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int cnt[123] = {};
        for (char c: s) cnt[c]++;
        bool used[123] = {};
        string res;
        for (char c: s) {
            if (!used[c]) {
                while (!res.empty() && res.back() > c && cnt[res.back()]) {
                    used[res.back()] = false;
                    res.pop_back();
                }
                res.push_back(c);
                used[c] = true;
            }
            cnt[c]--;
        }
        return res;
    }
};