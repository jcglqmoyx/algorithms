#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>> &synonyms, string text) {
        vector<string> words;
        stringstream ss(text);
        string word;
        while (ss >> word) words.push_back(word);
        unordered_map<string, unordered_set<string>> hash;
        for (auto &synonym: synonyms) add(synonym[0], synonym[1]);

        for (auto &s: synonyms) {
            hash[find(s[0])].insert(s[0]);
            hash[find(s[1])].insert(s[1]);
        }

        vector<string> res = {""};
        for (string &w: words) {
            if (hash.count(find(w))) {
                vector<string> tmp;
                for (string &sentence: res) {
                    for (const string &synonym: hash[find(w)]) {
                        tmp.push_back(sentence + synonym + ' ');
                    }
                }
                res = tmp;
            } else {
                for (string &s: res) {
                    s += w + ' ';
                }
            }
        }
        for (string &s: res) s.pop_back();
        sort(res.begin(), res.end());
        return res;
    }

private:
    unordered_map<string, string> p;

    string &find(string &x) {
        if (!p.count(x)) {
            p[x] = x;
        } else if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void add(string &x, string &y) {
        string &px = find(x), &py = find(y);
        if (px == py) return;
        p[px] = py;
    }
};