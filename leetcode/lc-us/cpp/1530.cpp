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
    int countPairs(TreeNode *root, int distance) {
        dfs(root, nullptr);
        int res = 0;
        unordered_set<TreeNode *> solved;
        for (auto node: leaves) {
            solved.insert(node);
            unordered_set<TreeNode *> vis;
            vis.insert(node);
            queue<TreeNode *> q;
            q.push(node);
            int dist = 0;
            while (!q.empty()) {
                dist++;
                if (dist > distance) break;
                for (size_t i = q.size(); i; i--) {
                    auto t = q.front();
                    q.pop();
                    for (auto ne: paths[t]) {
                        if (!vis.count(ne)) {
                            q.push(ne);
                            vis.insert(ne);
                            if (!ne->left && !ne->right && dist <= distance && !solved.count(ne)) {
                                res++;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

private:
    vector<TreeNode *> leaves;
    unordered_map<TreeNode *, vector<TreeNode *>> paths;

    void dfs(TreeNode *root, TreeNode *parent) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root);
        }
        if (parent) {
            paths[root].push_back(parent);
            paths[parent].push_back(root);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
};