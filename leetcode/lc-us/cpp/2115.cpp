#include <bits/stdc++.h>

using namespace std;

class Solution {
    using VS = vector<string>;

    unordered_map<string, VS> _ingredients;
    unordered_set<string> set;
    unordered_set<string> vis;

    bool dfs(string &r) {
        if (set.count(r)) return true;
        if (!_ingredients.count(r)) return false;
        if (vis.count(r)) return false;
        vis.insert(r);
        for (auto &ingredient: _ingredients[r]) {
            if (!dfs(ingredient)) return false;
            else set.insert(ingredient);
        }
        return true;
    }

public:
    VS findAllRecipes(VS &recipes, vector<VS> &ingredients, VS &supplies) {
        for (const auto &s: supplies) set.insert(s);
        for (int i = 0; i < (int) recipes.size(); i++) {
            for (auto &ingredient: ingredients[i]) {
                _ingredients[recipes[i]].push_back(ingredient);
            }
        }
        VS res;
        for (auto &r: recipes) {
            vis.clear();
            if (dfs(r)) {
                res.push_back(r);
            }
        }
        return res;
    }
};