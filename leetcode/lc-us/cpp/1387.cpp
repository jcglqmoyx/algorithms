#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        minimum = lo;
        map.resize(hi - lo + 1);
        nums.resize(hi - lo + 1);
        for (int i = lo; i <= hi; i++) {
            nums[i - lo] = i;
            map[i - lo] = power(i);
        }
        int position = random_partition(nums, 0, hi - lo);
        while (position != k - 1) {
            if (position < k - 1) position = random_partition(nums, position + 1, hi - lo);
            else if (position > k - 1) position = random_partition(nums, 0, position - 1);
        }
        return nums[k - 1];
    }

private:
    vector<int> map;
    vector<int> nums;
    int minimum;

    int power(int n) {
        int count = 0;
        while (n != 1) {
            count++;
            if ((n & 1)) n = n * 3 + 1;
            else n >>= 1;
        }
        return count;
    }

    int random_partition(vector<int> &arr, int low, int high) {
        if (low >= high) return low;
        int idx = rand() % (high - low + 1) + low;
        swap(arr[low], arr[idx]);
        int pivot = map[arr[low] - minimum];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && (map[arr[i] - minimum] < pivot || map[arr[i] - minimum] == pivot && arr[i] < arr[low]))
                i++;
            while (j > low && (map[arr[j] - minimum] > pivot || map[arr[j] - minimum] == pivot && arr[j] > arr[low]))
                j--;
            if (i >= j) break;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        swap(arr[low], arr[j]);
        return j;
    }
};