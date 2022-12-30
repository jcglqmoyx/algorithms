#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findDistance(TreeNode *root, int p, int q) {
        if (p == q) return 0;
        _p = p, _q = q;
        dfs(root, nullptr);
        queue<TreeNode *> Q;
        Q.push(start);
        int dist = 0;
        unordered_set<TreeNode *> S;
        S.insert(start);
        while (!Q.empty()) {
            dist++;
            for (size_t it = Q.size(); it; it--) {
                auto t = Q.front();
                Q.pop();
                for (auto node: g[t]) {
                    if (S.count(node)) continue;
                    if (node == end) return dist;
                    Q.push(node);
                    S.insert(node);
                }
            }
        }
        return -1;
    }

private:
    int _p, _q;
    TreeNode *start, *end;
    unordered_map<TreeNode *, vector<TreeNode *>> g;

    void dfs(TreeNode *root, TreeNode *parent) {
        if (!root) return;
        if (root->val == _p) start = root;
        else if (root->val == _q) end = root;
        if (parent) {
            g[root].push_back(parent);
            g[parent].push_back(root);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
};