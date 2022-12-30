#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        n = (int) nums.size(), arr = nums, path.resize(n), st.resize(n, false);
        sort(arr.begin(), arr.end());
        dfs(0);
        return paths;
    }

private:
    int n;
    vector<int> arr, path;
    vector<bool> st;
    vector<vector<int>> paths;

    void dfs(int index) {
        if (index == n) {
            paths.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (st[i] || i && arr[i] == arr[i - 1] && !st[i - 1]) continue;
            st[i] = true;
            path[index] = arr[i];
            dfs(index + 1);
            st[i] = false;
        }
    }
};