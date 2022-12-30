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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return construct(nums, 0, (int) nums.size() - 1);
    }

private:
    TreeNode *construct(const vector<int> &nums, int low, int high) {
        if (low > high) return nullptr;
        int mid = low + (high - low) / 2;
        auto *node = new TreeNode(nums[mid]);
        node->left = construct(nums, low, mid - 1);
        node->right = construct(nums, mid + 1, high);
        return node;
    }
};