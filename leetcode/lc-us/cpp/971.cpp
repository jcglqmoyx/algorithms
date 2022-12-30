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
    vector<int> res;

    bool dfs(TreeNode *root, vector<int> &v, int &k) {
        if (!root) return true;
        if (root->val != v[k]) return false;
        k++;
        if (root->left && root->left->val != v[k]) {
            res.push_back(root->val);
            return dfs(root->right, v, k) && dfs(root->left, v, k);
        } else {
            return dfs(root->left, v, k) && dfs(root->right, v, k);
        }
    }

public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        int k = 0;
        if (dfs(root, voyage, k)) return res;
        return {-1};
    }
};