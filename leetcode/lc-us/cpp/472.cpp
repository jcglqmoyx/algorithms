#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ULL = unsigned long long;
    static const int N = 1005;
    const int P = 131;

    int n;
    ULL h[N], p[N];
    unordered_set<ULL> set;

    void init() {
        h[0] = 0;
        p[0] = 1;
        for (int i = 1; i < N; i++) {
            p[i] = p[i - 1] * P;
        }
    }

    bool dfs(string &w, int u) {
        if (u == n) return true;
        for (int k = u; k < n; k++) {
            if (set.count(h[k + 1] - h[u] * p[k - u + 1])) {
                if (dfs(w, k + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(string &w) {
        n = (int) w.size();
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + w[i - 1];
        }
        if (!dfs(w, 0)) {
            set.insert(h[n]);
            return false;
        }
        return true;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        init();
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });
        vector<string> res;
        for (auto &word: words) {
            if (word.empty()) continue;
            if (check(word)) {
                res.push_back(word);
            }
        }
        return res;
    }
};