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
    int get(vector<int> &nums) {
        int res = 0;
        vector<int> t = nums;
        int n = (int) nums.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[t[i]] = i;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != nums[i]) {
                int p = pos[nums[i]];
                swap(t[i], t[p]);
                swap(pos[t[i]], pos[t[p]]);
                res++;
            }
        }
        return res;
    }

public:
    int minimumOperations(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            vector<int> v;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res += get(v);
        }
        return res;
    }
};