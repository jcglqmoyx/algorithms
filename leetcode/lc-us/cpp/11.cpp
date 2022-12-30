#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int low = 0, high = (int) height.size() - 1;
        while (low < high) {
            max_area = max(max_area, min(height[low], height[high]) * (high - low));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return max_area;
    }
};