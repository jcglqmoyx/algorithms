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
    int n;

    TreeNode *construct(string &s, int low, int high) {
        if (low > high) return nullptr;
        auto *root = new TreeNode();
        int i = low;
        while (i < n && s[i] != '(' && s[i] != ')') i++;
        if (i == low) return nullptr;
        root->val = stoi(s.substr(low, i - low));
        int cnt = 1;
        int j = i + 1;
        while (j < n && cnt != 0) {
            if (s[j] == '(') cnt++;
            else if (s[j] == ')') cnt--;
            j++;
        }
        root->left = construct(s, i + 1, j - 2);
        root->right = construct(s, j + 1, high);
        return root;
    }

public:
    TreeNode *str2tree(string s) {
        n = (int) s.size();
        return construct(s, 0, n - 1);
    }
};