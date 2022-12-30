#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    int u;
    string s;

    void dfs1(TreeNode *root) {
        if (!root) {
            s.push_back('#');
            return;
        }
        s += to_string(root->val) + ' ';
        dfs1(root->left);
        dfs1(root->right);
    }

    TreeNode *dfs2(string &data) {
        if (data[u] == '#') {
            u++;
            return nullptr;
        }
        int x = 0;
        while (data[u] != ' ') {
            x = x * 10 + data[u] - '0';
            u++;
        }
        u++;
        auto root = new TreeNode(x);
        root->left = dfs2(data);
        root->right = dfs2(data);
        return root;
    }

public:
    string serialize(TreeNode *root) {
        s = "";
        dfs1(root);
        return s;
    }

    TreeNode *deserialize(string data) {
        u = 0;
        return dfs2(data);
    }
};