#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        int max_len = 0;
        int count = 0;
        for (vector<int> rectangle: rectangles) {
            int len = min(rectangle[0], rectangle[1]);
            if (len > max_len) {
                max_len = len;
                count = 1;
            } else if (len == max_len) count++;
        }
        return count;
    }
};