#include <vector>

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums, 0, (int) nums.size() - 1);
    }

private:
    int find_max(const vector<int> &nums, int low, int high) {
        if (low > high) {
            return -1;
        }
        int index = low, max_num = nums[low];
        for (int i = low + 1; i <= high; i++) {
            if (nums[i] > max_num) {
                max_num = nums[i];
                index = i;
            }
        }
        return index;
    }

    TreeNode *construct(const vector<int> &nums, int low, int high) {
        int index = find_max(nums, low, high);
        if (index == -1) {
            return nullptr;
        }
        auto node = new TreeNode(nums[index]);
        node->left = construct(nums, low, index - 1);
        node->right = construct(nums, index + 1, high);
        return node;
    }
};