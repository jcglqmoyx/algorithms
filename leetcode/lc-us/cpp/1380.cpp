#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        vector<int> lucky_numbers;
        for (int row = 0; row < matrix.size(); row++) {
            int col = min_index_in_row(matrix, row);
            if (max_index_in_column(matrix, col) == row) {
                lucky_numbers.push_back(matrix[row][col]);
            }
        }
        return lucky_numbers;
    }

private:
    static int min_index_in_row(vector<vector<int>> &matrix, int row) {
        int min_element = INT32_MAX;
        int index = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[row][i] < min_element) {
                min_element = matrix[row][i];
                index = i;
            }
        }
        return index;
    }

    static int max_index_in_column(vector<vector<int>> &matrix, int col) {
        int max_element = INT32_MIN;
        int index = 0;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][col] > max_element) {
                max_element = matrix[i][col];
                index = i;
            }
        }
        return index;
    }
};