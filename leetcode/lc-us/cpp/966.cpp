#include <bits/stdc++.h>

using namespace std;

class Solution {
    string to_uppercase(string &s) {
        string t = s;
        for (char &c: t) c = toupper(c);
        return t;
    }

    string filter(string &s) {
        string t = to_uppercase(s);
        for (char &c: t) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') c = 'A';
        }
        return t;
    }

public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries) {
        unordered_map<string, string> m1, m2, m3;
        for (auto &w: wordlist) {
            m1[w] = w;
            string w2 = to_uppercase(w);
            if (!m2.count(w2)) m2[w2] = w;
            string w3 = filter(w);
            if (!m3.count(w3)) m3[w3] = w;
        }
        int n = (int) queries.size();
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            string &key = queries[i];
            if (m1.count(key)) res[i] = m1[key];
            else if (m2.count(to_uppercase(key))) res[i] = m2[to_uppercase(key)];
            else if (m3.count(filter(key))) res[i] = m3[filter(key)];
            else res[i] = "";
        }
        return res;
    }
};