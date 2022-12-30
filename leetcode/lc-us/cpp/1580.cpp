#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int> &boxes, vector<int> &warehouse) {
        int m = (int) boxes.size(), n = (int) warehouse.size();
        int min_height = INT32_MAX, min_index = 0;
        for (int i = 0; i < n; i++) {
            if (warehouse[i] < min_height) {
                min_height = warehouse[i];
                min_index = i;
            }
        }
        for (int i = 0, mn = INT32_MAX; i < min_index; i++) {
            mn = min(mn, warehouse[i]);
            warehouse[i] = mn;
        }
        for (int i = n - 1, mn = INT32_MAX; i > min_index; i--) {
            mn = min(mn, warehouse[i]);
            warehouse[i] = mn;
        }
        int cnt = 0;
        sort(boxes.begin(), boxes.end());
        sort(warehouse.begin(), warehouse.end());
        for (int i = 0, j = 0; i < m && j < n;) {
            while (j < n && warehouse[j] < boxes[i]) j++;
            if (j < n) i++, j++, cnt++;
        }
        return cnt;
    }
};