#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size(), 0));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int sum = 0, count = 0;
                for (int m = i - 1; m <= i + 1; m++) {
                    for (int n = j - 1; n <= j + 1; n++) {
                        if (m >= 0 && m < img.size() && n >= 0 && n < img[0].size()) {
                            sum += img[m][n];
                            count++;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};