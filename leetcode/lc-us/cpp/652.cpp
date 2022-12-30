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
    unordered_map<string, int> ids;
    unordered_map<int, int> map;
    vector<TreeNode *> ans;
    int cnt = 0;

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        string key = to_string(node->val) + ' ' + to_string(left) + ' ' + to_string(right);
        if (ids.find(key) == ids.end()) {
            ids[key] = ++cnt;
        }
        int id = ids[key];
        if (++map[id] == 2) ans.push_back(node);
        return id;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        return ans;
    }
};
