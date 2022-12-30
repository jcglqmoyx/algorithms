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
    unordered_map<int, int> cnt;

    int dfs(TreeNode *root) {
        int l = 0, r = 0;
        if (root->left) l = dfs(root->left);
        if (root->right) r = dfs(root->right);
        int sum = l + r + root->val;
        cnt[sum]++;
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> res;
        dfs(root);
        int ans = 0;
        for (auto &x: cnt) {
            ans = max(ans, x.second);
        }
        for (auto &x: cnt) {
            if (x.second == ans) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};