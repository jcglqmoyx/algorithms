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
    TreeNode *canMerge(vector<TreeNode *> &trees) {
        const int N = 50010;

        int deg[N] = {};
        TreeNode *M[N] = {};
        vector<int> nums;
        for (auto &r: trees) {
            M[r->val] = r;
            nums.push_back(r->val);
            auto L = r->left, R = r->right;
            if (L) {
                int v = L->val;
                deg[v]++, nums.push_back(v);
            }
            if (R) {
                int v = R->val;
                deg[v]++, nums.push_back(v);
            }
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        queue<TreeNode *> q;
        TreeNode *res = nullptr;
        for (int i = 0; i < N; i++) {
            if (!deg[i] && M[i]) {
                q.push(M[i]);
                res = M[i];
            }
        }
        if (q.size() > 1) return nullptr;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto l = t->left, r = t->right;
            if (l && M[l->val] && --deg[l->val] == 0) t->left = M[l->val], q.push(M[l->val]);
            if (r && M[r->val] && --deg[r->val] == 0) t->right = M[r->val], q.push(M[r->val]);
        }
        vector<int> v;
        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            if (!root) return;
            dfs(root->left);
            v.push_back(root->val);
            dfs(root->right);
        };
        dfs(res);
        if (v.size() != nums.size()) return nullptr;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != nums[i]) return nullptr;
        }
        return res;
    }
};
