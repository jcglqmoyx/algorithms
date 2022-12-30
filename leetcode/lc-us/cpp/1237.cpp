#include <bits/stdc++.h>

using namespace std;

class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        vector<vector<int>> solutions;
        for (int x = 1; x <= 1000; x++) {
            int low = 1, high = 1000;
            while (low < high) {
                int mid = low + (high - low) / 2;
                int result = customfunction.f(x, mid);
                if (result == z) {
                    solutions.push_back({x, mid});
                    break;
                } else if (result > z) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return solutions;
    }
};