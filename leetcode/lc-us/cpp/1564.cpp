#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int> &boxes, vector<int> &warehouse) {
        int n = (int) boxes.size(), m = (int) warehouse.size();
        vector<int> h(m), idx(m);
        for (int i = 0, min_height = 1e9, min_height_index = 0; i < m; i++) {
            if (warehouse[i] < min_height) min_height = warehouse[i], min_height_index = i;
            h[i] = min_height, idx[i] = min_height_index;
        }
        int i = 0, j = m - 1;
        sort(boxes.begin(), boxes.end());
        for (; i < n && j >= 0;) {
            while (j >= 0 && warehouse[j] < boxes[i]) j--;
            if (j >= 0) {
                if (h[j] >= boxes[i]) i++, j--;
                else j = idx[j] - 1;
            } else break;
        }
        return i;
    }
};