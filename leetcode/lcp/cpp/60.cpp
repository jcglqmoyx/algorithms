#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<tuple<int, int, int, int>>> v;
    vector<pair<int, int>> remove_list;

    int collect(int lvl, TreeNode *node) {
        if (!node) return 0;
        while (lvl + 1 >= v.size()) v.push_back({{0, -1, -1, -1}});
        v[lvl].emplace_back(get<0>(v[lvl].back()) + node->val, -1, v[lvl + 1].size(), -1);
        node->val = (int) v[lvl].size() - 1;
        if (collect(lvl + 1, node->left) + collect(lvl + 1, node->right) != 2) {
            remove_list.emplace_back((int) v[lvl].size() - 1, lvl);
        }
        get<3>(v[lvl].back()) = (int) v[lvl + 1].size() - 1;
        return 1;
    }

    int getMaxLayerSum(TreeNode *root) {
        collect(0, root);

        int height = (int) v.size() - 1, res = INT_MIN;
        for (int lvl = 0; lvl < height; ++lvl) {
            res = max(res, get<0>(v[lvl].back()));
        }

        for (int idx = 0; idx < remove_list.size(); ++idx) {
            auto[node, start] = remove_list[idx];
            int left = node, right = node;
            int lost = get<0>(v[start][left]) - get<0>(v[start][left - 1]);
            for (int lvl = start; lvl < height; ++lvl) {
                if (left > right) break;
                if (right - left + 1 == v[lvl].size() - 1) break;

                auto&[l_sum, l_use, ne_left, _unused1] = v[lvl][left];
                auto&[r_sum, r_use, _unused2, ne_right] = v[lvl][right];

                if (l_use != -1 && l_use == r_use) break;
                l_use = r_use = idx;

                int add = 0;
                if (ne_left <= ne_right) {
                    add = get<0>(v[lvl + 1][ne_right]) - get<0>(v[lvl + 1][ne_left - 1]);
                }
                res = max(res, get<0>(v[lvl].back()) - lost + add);
                left = ne_left, right = ne_right, lost = add;
            }
        }

        return res;
    }
};