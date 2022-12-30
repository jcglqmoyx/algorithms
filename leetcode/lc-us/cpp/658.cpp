#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = (int) arr.size();
        int p = (int) (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        int left = p - 1, right = p;
        while (k--) {
            if (left < 0 || right < n && x - arr[left] > arr[right] - x) {
                right++;
            } else if (right == n || ~left && x - arr[left] <= arr[right] - x) {
                left--;
            }
        }
        return {arr.begin() + left + 1, arr.begin() + right};
    }
};