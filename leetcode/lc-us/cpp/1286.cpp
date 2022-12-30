#include <bits/stdc++.h>

using namespace std;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        len = combinationLength, i = 0;
        dfs(characters, 0);
    }

    string next() {
        string &s = res[i++];
        return s;
    }

    bool hasNext() {
        return i < res.size();
    }

private:
    int len, i;
    string cur;
    vector<string> res;

    void dfs(string &s, int index) {
        if (cur.size() == len) {
            res.push_back(cur);
            return;
        }
        if (index == s.size()) return;
        cur.push_back(s[index]);
        dfs(s, index + 1);
        cur.pop_back();
        dfs(s, index + 1);
    }
};