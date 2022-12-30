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
    unordered_map<int, int> map;

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        int sum = l + r + root->val;
        map[sum]++;
        return sum;
    }

public:
    bool checkEqualTree(TreeNode *root) {
        int tot = dfs(root);
        if (tot & 1) return false;
        if (tot && map.count(tot / 2)) {
            return true;
        }
        if (!tot && map[0] >= 2) {
            return true;
        }
        return false;
    }
};