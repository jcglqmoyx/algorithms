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
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root) return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, 0});
        while (!nodes.empty()) {
            auto[node, offset] = nodes.front();
            nodes.pop();
            m[offset].push_back(node->val);
            if (node->left) {
                nodes.push({node->left, offset - 1});
            }
            if (node->right) {
                nodes.push({node->right, offset + 1});
            }
        }
        vector<vector<int>> res;
        res.reserve(m.size());
        for (auto &x: m) {
            res.push_back(x.second);
        }
        return res;
    }
};