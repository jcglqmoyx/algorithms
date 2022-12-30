#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(string sentence, int k) {
        if (sentence.size() <= k) return 0;
        vector<int> len;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            len.push_back((int) word.size());
        }
        int n = (int) len.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + len[i - 1];
        }
        vector<int> f(n, 1e9);
        f[0] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i - 1; ~j; j--) {
                int dt = s[i] - s[j] + (i - j - 1);
                if (dt > k) break;
                f[i] = min(f[i], f[j] + (k - dt) * (k - dt));
            }
        }
        int res = f[n - 1];
        for (int i = n - 2; i; i--) {
            if (s.back() - s[i] + n - i - 1 <= k) res = min(res, f[i]);
        }
        return res;
    }
};