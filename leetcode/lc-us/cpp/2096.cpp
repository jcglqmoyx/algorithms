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
    string getDirections(TreeNode *root, int startValue, int destValue) {
        lowest_common_ancestor(root, startValue, destValue);
        string path1, path2, path;
        find_path(lca, startValue, path1, path);
        find_path(lca, destValue, path2, path);
        for (int i = 0; i < path1.size(); i++) path.push_back('U');
        path += path2;
        return path;
    }

private:
    TreeNode *lca;

    bool lowest_common_ancestor(TreeNode *root, int p, int q) {
        if (!root) return false;
        bool l = lowest_common_ancestor(root->left, p, q), r = lowest_common_ancestor(root->right, p, q);
        if (l && r || (root->val == p || root->val == q) && (l || r)) lca = root;
        return l || r || root->val == p || root->val == q;
    }

    void find_path(TreeNode *root, int goal, string &res, string &path) {
        if (!root) return;
        if (root->val == goal) {
            res = path;
            return;
        }
        path.push_back('L');
        find_path(root->left, goal, res, path);
        path.pop_back();
        path.push_back('R');
        find_path(root->right, goal, res, path);
        path.pop_back();
    }
};
