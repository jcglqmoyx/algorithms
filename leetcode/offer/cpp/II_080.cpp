#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return combinations;
    }

private:
    vector<int> combination;
    vector<vector<int>> combinations;

    void dfs(int index, int n, int k) {
        if (combination.size() > k) return;
        if (index == n + 1) {
            if (combination.size() == k) {
                combinations.push_back(combination);
            }
            return;
        }
        combination.push_back(index);
        dfs(index + 1, n, k);
        combination.pop_back();
        dfs(index + 1, n, k);
    }
};