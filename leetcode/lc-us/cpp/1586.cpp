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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        auto t = root;
        while (t) {
            stk.push(t);
            t = t->left;
        }
        i = -1;
    }

    bool hasNext() {
        if (i == (int) nums.size() - 1 && stk.empty()) return false;
        return true;
    }

    int next() {
        if (i < (int) nums.size() - 1) {
            return nums[++i];
        }
        auto t = stk.top();
        stk.pop();
        nums.push_back(t->val);
        if (t->right) {
            t = t->right;
            while (t) {
                stk.push(t);
                t = t->left;
            }
        }
        return nums[++i];
    }

    bool hasPrev() {
        return i > 0;
    }

    int prev() {
        return nums[--i];
    }

private:
    int i;
    vector<int> nums;
    stack<TreeNode *> stk;
};