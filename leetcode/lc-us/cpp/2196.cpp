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
    unordered_map<int, pair<int, int>> M;

    TreeNode *dfs(int root) {
        if (!root) return nullptr;
        int left = M[root].first;
        int right = M[root].second;
        auto *res = new TreeNode(root);
        if (!left) res->left = nullptr;
        if (!right) res->right = nullptr;
        res->left = dfs(M[root].first);
        res->right = dfs(M[root].second);
        return res;
    }

public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, int> deg;
        for (auto &d: descriptions) {
            int p = d[0], c = d[1], flag = d[2];
            if (flag) M[p].first = c;
            else M[p].second = c;
            deg[c]++;
        }
        int root = -1;
        for (auto &d: descriptions) {
            int p = d[0], c = d[1], flag = d[2];
            if (!deg.count(p)) {
                root = p;
                break;
            }
        }
        return dfs(root);
    }
};