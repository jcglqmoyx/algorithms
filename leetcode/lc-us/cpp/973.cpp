#include <bits/stdc++.h>

using namespace std;

class Solution {
    void partition(vector<vector<int>> &points, int low, int high, int k) {
        int random_index = rand() % (high - low + 1) + low;
        swap(points[low], points[random_index]);
        int pivot = points[low][0] * points[low][0] + points[low][1] * points[low][1];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && points[i][0] * points[i][0] + points[i][1] * points[i][1] < pivot) i++;
            while (j > low && points[j][0] * points[j][0] + points[j][1] * points[j][1] > pivot) j--;
            if (i >= j) break;
            swap(points[i], points[j]);
            i++;
            j--;
        }
        swap(points[low], points[j]);
        if (j < k - 1) partition(points, j + 1, high, k);
        else if (j > k - 1) partition(points, low, j - 1, k);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        partition(points, 0, (int) points.size() - 1, K);
        return {points.begin(), points.begin() + K};
    }
};