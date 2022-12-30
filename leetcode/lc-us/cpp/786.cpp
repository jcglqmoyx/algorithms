#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        double l = 0, r = 1;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (get(arr, mid) >= k) r = mid;
            else l = mid;
        }
        return {a, b};
    }

private:
    const double eps = 1e-8;
    int a{}, b{};

    int get(vector<int> &arr, double mid) {
        int res = 0;
        for (int i = 1, j = 0; i < arr.size(); i++) {
            while ((double) arr[j] / arr[i] <= mid) j++;
            res += j;
            if (j && fabs((double) arr[j - 1] / arr[i] - mid) <= eps) a = arr[j - 1], b = arr[i];
        }
        return res;
    }
};