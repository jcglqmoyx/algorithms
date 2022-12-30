#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        if (!tree) return {};
        vector<ListNode *> res;
        queue<TreeNode *> q;
        q.push(tree);
        while (!q.empty()) {
            auto *list = new ListNode(0), *dummy = list;
            for (auto it = q.size(); it; it--) {
                TreeNode *node = q.front();
                q.pop();
                list->next = new ListNode(node->val);
                list = list->next;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(dummy->next);
        }
        return res;
    }
};