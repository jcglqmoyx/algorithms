#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int n = (int) mat.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int max_up = mid == 0 ? -1 : *max_element(mat[mid - 1].begin(), mat[mid - 1].end());
            int max_bottom = mid == n - 1 ? -1 : *max_element(mat[mid + 1].begin(), mat[mid + 1].end());
            auto mx = max_element(mat[mid].begin(), mat[mid].end());
            if (*mx >= max(max_up, max_bottom)) return {mid, (int) (mx - mat[mid].begin())};
            else if (max_up >= max(*mx, max_bottom)) r = mid;
            else l = mid + 1;
        }
        return {l, (int) (max_element(mat[l].begin(), mat[l].end()) - mat[l].begin())};
    }
};