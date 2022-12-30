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
    TreeNode *construct(string &s, int l, int r) {
        if (l > r) return nullptr;
        auto root = new TreeNode();
        int i = l + 1;
        while (i <= r && isdigit(s[i])) i++;
        root->val = stoi(s.substr(l, i - l));
        l = i;
        while (i <= r && s[i] == '-') i++;
        int dash = i - l;
        int j = i;
        int idx = -1;
        while (j <= r) {
            if (s[j] == '-') {
                int k = j + 1;
                while (k <= r && s[k] == '-') k++;
                if (k - j == dash) {
                    idx = k;
                    break;
                }
                j = k;
            }
            j++;
        }
        if (idx != -1) {
            root->left = construct(s, i, idx - dash - 1);
            root->right = construct(s, idx, r);
        } else {
            root->left = construct(s, i, r);
        }
        return root;
    }

public:
    TreeNode *recoverFromPreorder(string traversal) {
        return construct(traversal, 0, (int) traversal.size() - 1);
    }
};