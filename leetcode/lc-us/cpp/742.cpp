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

const int N = 2005;

bool st[N], is_leaf[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    int findClosestLeaf(TreeNode *root, int k) {
        memset(st, false, sizeof st), memset(is_leaf, false, sizeof is_leaf);
        memset(h, -1, sizeof h), memset(e, 0, sizeof e), memset(ne, -1, sizeof ne), idx = 0;
        dfs(root, nullptr);
        queue<int> q;
        q.push(k);
        st[k] = true;
        while (!q.empty()) {
            for (size_t it = q.size(); it; it--) {
                int t = q.front();
                q.pop();
                int cnt = 0;
                for (int i = h[t]; i != -1; i = ne[i]) {
                    int j = e[i];
                    cnt++;
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
                if (cnt <= 1 && is_leaf[t]) return t;
            }
        }
        return 0;
    }

private:
    void dfs(TreeNode *node, TreeNode *p) {
        if (!node) return;
        if (p) add(p->val, node->val), add(node->val, p->val);
        if (!node->left && !node->right) is_leaf[node->val] = true;
        dfs(node->left, node), dfs(node->right, node);
    }
};