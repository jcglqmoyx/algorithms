#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode *root) {
        if (!root) return "";
        string s;
        dfs1(root, s);
        return s;
    }

    TreeNode *deserialize(string data) {
        if (data.empty()) return nullptr;
        int u = 0;
        return dfs2(data, u);
    }

private:
    void dfs1(TreeNode *root, string &s) {
        if (!root) {
            s += "null ";
            return;
        }
        s += to_string(root->val) + ' ';
        dfs1(root->left, s), dfs1(root->right, s);
    }

    TreeNode *dfs2(string &s, int &u) {
        if (s[u] == 'n') {
            u += 5;
            return nullptr;
        }
        int i = u + 1;
        while (i < (int) s.size() && isdigit(s[i])) i++;
        auto root = new TreeNode(stoi(s.substr(u, i - u)));
        u = i + 1;
        root->left = dfs2(s, u), root->right = dfs2(s, u);
        return root;
    }
};