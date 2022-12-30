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
        string res;
        dfs_s(root, res);
        return res;
    }

    TreeNode *deserialize(string data) {
        int index = 0;
        return dfs_d(data, index);
    }

private:
    void dfs_s(TreeNode *root, string &res) {
        if (!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    TreeNode *dfs_d(string &data, int &index) {
        if (index == data.length()) return nullptr;
        int k = index;
        while (k < data.length() && data[k] != ' ') {
            k++;
        }
        if (data[index] == 'n') {
            index = k + 1;
            return nullptr;
        }
        int val = stoi(data.substr(index, k - index));
        index = k + 1;
        auto *root = new TreeNode(val);
        root->left = dfs_d(data, index);
        root->right = dfs_d(data, index);
        return root;
    }
};