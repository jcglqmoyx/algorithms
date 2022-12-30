#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(string a, string b) {
        int len = (int) a.size();
        int i = 0, j = 0;
        while (i < len && j < len - 1) {
            if (a[i] == b[j]) {
                j++;
            }
            i++;
        }
        return j == len - 1;
    }

public:
    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &u, const string &v) {
            return u.size() < v.size();
        });
        int n = (int) words.size();
        vector<int> f(n + 5, 1);
        for (int i = 1; i < n; i++) {
            int len1 = (int) words[i].size();
            for (int j = i - 1; j >= 0; j--) {
                if (words[j].size() == len1 - 1) {
                    if (check(words[i], words[j])) {
                        f[i] = max(f[i], f[j] + 1);
                    }
                }
            }
        }
        int ans = f[0];
        for (auto i: f) ans = max(ans, i);
        return ans;
    }
};