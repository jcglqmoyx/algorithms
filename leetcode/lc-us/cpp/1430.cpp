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
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        n = (int) arr.size(), flag = false;
        dfs(root, arr, 0);
        return flag;
    }

private:
    int n;
    bool flag;

    void dfs(TreeNode *node, vector<int> &arr, int u) {
        if (!node || flag || u == n) return;
        if (node->val != arr[u]) return;
        if (u == n - 1 && !node->left && !node->right) {
            flag = true;
            return;
        }
        dfs(node->left, arr, u + 1);
        dfs(node->right, arr, u + 1);
    }
};