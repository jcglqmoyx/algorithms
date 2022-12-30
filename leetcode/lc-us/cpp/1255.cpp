#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, res;
    vector<string> _words;
    vector<int> cnt, _score;

    void dfs(int u, int s) {
        if (u == n) {
            res = max(res, s);
            return;
        }
        bool flag = true;
        int t = 0;
        for (char c: _words[u]) {
            cnt[c - 'a']--;
            t += _score[c - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] < 0) {
                flag = false;
                break;
            }
        }
        if (flag) dfs(u + 1, s + t);
        for (char c: _words[u]) cnt[c - 'a']++;

        dfs(u + 1, s);
    }

public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        n = (int) words.size(), res = 0, _words = words, cnt.resize(26), _score = score;
        for (char c: letters) cnt[c - 'a']++;
        dfs(0, 0);
        return res;
    }
};