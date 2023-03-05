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
    long long kthLargestLevelSum(TreeNode *root, int k) {
        using LL = long long;
        queue<TreeNode *> q;
        q.push(root);
        vector<LL> v;
        while (!q.empty()) {
            LL s = 0;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                s += t->val;
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            v.push_back(s);
        }
        int n = (int) v.size();
        if (n < k) return -1;
        nth_element(v.begin(), v.begin() + n - k, v.end());
        return v[n - k];
    }
};