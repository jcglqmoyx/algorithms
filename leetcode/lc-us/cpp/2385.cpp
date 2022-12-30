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

const int N = 1e5 + 10, M = N << 1;

int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            add(root->val, root->left->val);
            add(root->left->val, root->val);
            dfs(root->left);
        }
        if (root->right) {
            add(root->val, root->right->val);
            add(root->right->val, root->val);
            dfs(root->right);
        }
    }

public:
    int amountOfTime(TreeNode *root, int start) {
        memset(h, -1, sizeof h), idx = 0;
        memset(st, false, sizeof st);

        dfs(root);

        queue<int> q;
        q.push(start);
        st[start] = true;
        int res = -1;
        while (!q.empty()) {
            res++;
            for (auto it = q.size(); it; it--) {
                int x = q.front();
                q.pop();
                for (int i = h[x]; i != -1; i = ne[i]) {
                    int j = e[i];
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
        return res;
    }
};