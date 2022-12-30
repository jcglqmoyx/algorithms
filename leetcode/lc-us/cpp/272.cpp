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
    void dfs(TreeNode *root, vector<int> &v) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }

    vector<int> closestKValues(TreeNode *root, double target, int k) {
        vector<int> v;
        dfs(root, v);
        vector<int> res;
        int n = (int) v.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (v[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int i = l, j = i + 1;
        if (j == n) {
            for (int u = n - 1; n - u <= k; u--) {
                res.push_back(v[u]);
            }
            return res;
        }
        while (res.size() < k) {
            if (j == n) {
                while (res.size() < k) {
                    res.push_back(v[i]);
                    i--;
                }
            } else if (i == -1) {
                while (res.size() < k) {
                    res.push_back(v[j]);
                    j++;
                }
            } else {
                double da = abs(v[i] - target);
                double db = abs(v[j] - target);
                if (da < db) {
                    res.push_back(v[i]);
                    i--;
                } else {
                    res.push_back(v[j]);
                    j++;
                }
            }
        }
        return res;
    }
};