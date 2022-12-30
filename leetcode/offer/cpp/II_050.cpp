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
    int pathSum(TreeNode *root, int targetSum) {
        int cnt = 0;
        unordered_map<long long, int> hash;
        hash[0] = 1;
        dfs(root, hash, 0, targetSum, cnt);
        return cnt;
    }

private:
    void dfs(TreeNode *node, unordered_map<long long, int> &hash, long long sum, int target, int &cnt) {
        if (!node) return;
        sum += node->val;
        if (hash.count(sum - target)) cnt += hash[sum - target];
        hash[sum]++;
        dfs(node->left, hash, sum, target, cnt);
        dfs(node->right, hash, sum, target, cnt);
        hash[sum]--;
        if (hash[sum] == 0) hash.erase(sum);
    }
};