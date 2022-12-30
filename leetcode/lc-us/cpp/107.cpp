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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> nums;
            nums.reserve(nodes.size());
            for (int i = (int) nodes.size() - 1; i >= 0; i--) {
                nums.push_back(nodes.front()->val);
                if (nodes.front()->left) nodes.push(nodes.front()->left);
                if (nodes.front()->right) nodes.push(nodes.front()->right);
                nodes.pop();
            }
            res.push_back(nums);
        }
        for (int i = 0; i < res.size() / 2; i++) {
            swap(res[i], res[res.size() - i - 1]);
        }
        return res;
    }
};