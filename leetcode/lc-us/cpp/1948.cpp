#include <bits/stdc++.h>

using namespace std;

struct Trie {
    string serial;
    unordered_map<string, Trie *> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
        auto root = new Trie();
        for (auto &p: paths) {
            auto trie = root;
            for (auto &s: p) {
                if (!trie->children.count(s)) {
                    trie->children[s] = new Trie();
                }
                trie = trie->children[s];
            }
        }
        unordered_map<string, int> freq;
        function<void(Trie *)> construct = [&](Trie *node) {
            if (node->children.empty()) return;
            vector<string> v;
            for (auto &[k, c]: node->children) {
                construct(c);
                v.push_back(k + '(' + c->serial + ')');
            }
            sort(v.begin(), v.end());
            for (auto &s: v) {
                node->serial += s;
            }
            freq[node->serial]++;
        };
        construct(root);

        vector<string> path;
        vector<vector<string>> res;
        function<void(Trie *)> operate = [&](Trie *node) {
            if (freq[node->serial] > 1) return;
            if (!path.empty()) res.push_back(path);
            for (auto &[k, v]: node->children) {
                path.push_back(k);
                operate(v);
                path.pop_back();
            }
        };
        operate(root);
        return res;
    }
};