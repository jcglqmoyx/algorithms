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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        hash[root] = {0, 1};
        dfs(root->left, -1, 2);
        dfs(root->right, 1, 2);
        vector<vector<int>> nodes;
        for (auto &[k, v]: hash) nodes.push_back({k->val, v.first, v.second});
        sort(nodes.begin(), nodes.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[1] != b[1]) return a[1] < b[1];
            if (a[2] != b[2]) return a[2] < b[2];
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int n = (int) nodes.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && nodes[j][1] == nodes[i][1]) j++;
            vector<int> v;
            for (int k = i; k < j; k++) v.push_back(nodes[k][0]);
            res.push_back(v);
            i = j - 1;
        }
        return res;
    }

private:
    unordered_map<TreeNode *, pair<int, int>> hash;

    void dfs(TreeNode *root, int col, int depth) {
        if (!root) return;
        hash[root] = {col, depth};
        dfs(root->left, col - 1, depth + 1);
        dfs(root->right, col + 1, depth + 1);
    }
};