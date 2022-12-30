#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxValue(TreeNode *root, int k) {
        auto t = dfs(root, k);
        return *max_element(t.begin(), t.end());
    }

private:
    vector<int> dfs(TreeNode *root, int k) {
        vector<int> res(k + 1);
        if (!root) return res;
        auto l = dfs(root->left, k), r = dfs(root->right, k);
        for (int i = 0; i <= k; i++) {
            if (i == 0) {
                res[i] = *max_element(l.begin(), l.end()) + *max_element(r.begin(), r.end());
            } else {
                res[i] = root->val;
                int t = 0;
                for (int left = 0; left < i; left++) {
                    int right = i - left - 1;
                    t = max(t, l[left] + r[right]);
                }
                res[i] += t;
            }
        }
        return res;
    }
};