#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &arr, int target) {
        return find(arr, 0, (int) arr.size() - 1, target);
    }

private:
    int find(vector<int> &arr, int left, int right, int target) {
        while (left <= right) {
            if (arr[left] < arr[right]) {
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] == target) {
                        right = mid;
                    } else if (arr[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (arr[left] == target) {
                    return left;
                }
            } else {
                int mid = left + (right - left) / 2;
                if (arr[mid] > arr[left]) {
                    int ret = find(arr, left, mid, target);
                    if (ret != -1) {
                        return ret;
                    }
                }
                if (arr[left] == target) {
                    return left;
                }
                left++;
            }
        }
        return -1;
    }
};