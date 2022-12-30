#include <bits/stdc++.h>

using namespace std;

class WordFilter {
    unordered_map<string, int> m;
public:
    WordFilter(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            auto &s = words[i];
            int n = (int) s.size();
            for (int pre = 1; pre <= n; pre++) {
                string prefix = s.substr(0, pre);
                for (int suf = 1; suf <= n; suf++) {
                    string suffix = s.substr(n - suf);
                    string str = prefix;
                    str.push_back(' ');
                    str.append(suffix);
                    m[str] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + ' ' + suffix;
        if (m.count(s)) return m[s];
        return -1;
    }
};