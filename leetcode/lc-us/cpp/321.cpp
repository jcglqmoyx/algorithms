#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = (int) nums1.size(), m = (int) nums2.size();
        vector<int> res;
        for (int i = max(0, k - m); i <= min(k, n); i++) {
            auto a = get(nums1, i);
            auto b = get(nums2, k - i);
            auto c = merge(a, b, k);
            res = max(res, c);
        }
        return res;
    }

private:
    vector<int> get(vector<int> &arr, int len) {
        int n = (int) arr.size();
        vector<int> res(len);
        for (int i = 0, j = 0; i < n; i++) {
            while (j && j + n - i > len && arr[i] > res[j - 1]) j--;
            if (j < len) res[j++] = arr[i];
        }
        return res;
    }

    vector<int> merge(vector<int> &a, vector<int> &b, int k) {
        vector<int> res(k);
        int idx = 0;
        while (!a.empty() && !b.empty()) {
            if (a > b) res[idx++] = a[0], a.erase(a.begin());
            else res[idx++] = b[0], b.erase(b.begin());
        }
        if (!a.empty()) {
            for (int x: a) {
                res[idx++] = x;
            }
        } else if (!b.empty()) {
            for (int x: b) {
                res[idx++] = x;
            }
        }
        return res;
    }
};