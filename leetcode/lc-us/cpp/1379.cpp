#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *target_copy;

    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (!original) {
            return;
        }
        if (original == target) {
            target_copy = cloned;
            return;
        }
        dfs(original->left, cloned->left, target);
        dfs(original->right, cloned->right, target);
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        dfs(original, cloned, target);
        return target_copy;
    }
};