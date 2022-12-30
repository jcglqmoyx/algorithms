#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string boldWords(vector<string> &words, string s) {
        int n = (int) s.size();
        st.resize(n);
        for (auto &w: words) {
            process(s, w);
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (!st[i]) res.push_back(s[i]);
            else {
                res += "<b>";
                int j = i + 1;
                while (j < n && st[j]) j++;
                res += s.substr(i, j - i);
                i = j - 1;
                res += "</b>";
            }
        }
        return res;
    }

private:
    vector<bool> st;

    void process(string &s, string &w) {
        int n = (int) s.size(), m = (int) w.size();
        vector<int> ne(m, -1);
        for (int i = 1, j = -1; i < m; i++) {
            while (j != -1 && w[i] != w[j + 1]) j = ne[j];
            if (w[i] == w[j + 1]) j++;
            ne[i] = j;
        }
        for (int i = 0, j = -1; i < n; i++) {
            while (j != -1 && s[i] != w[j + 1]) j = ne[j];
            if (s[i] == w[j + 1]) j++;
            if (j == m - 1) {
                for (int idx = i - j; idx <= i; idx++) st[idx] = true;
                j = ne[j];
            }
        }
    }
};