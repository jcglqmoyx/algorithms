#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node *left;
    Node *right;

    Node() : val(' '), left(nullptr), right(nullptr) {}

    Node(char x) : val(x), left(nullptr), right(nullptr) {}

    Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
    int a[26], b[26];

    void dfs(Node *root, int cnt[]) {
        if (!root) return;
        if (root->val == '+') {
            dfs(root->left, cnt), dfs(root->right, cnt);
        } else {
            cnt[root->val - 'a']++;
        }
    }

public:
    bool checkEquivalence(Node *root1, Node *root2) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        dfs(root1, a), dfs(root2, b);
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};