#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int> &arr) {
        int n = (int) arr.size();
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) pos[arr[i]] = i;
        vector<int> flips;
        for (int i = n; i; i--) {
            int index = pos[i];
            if (index != i - 1) {
                flip(index, arr, pos);
                flip(i - 1, arr, pos);
                flips.push_back(index + 1);
                flips.push_back(i);
            }
        }
        return flips;
    }

private:
    void flip(int high, vector<int> &arr, vector<int> &pos) {
        int low = 0;
        while (low < high) {
            int l = arr[low], r = arr[high];
            swap(pos[l], pos[r]), swap(arr[low], arr[high]);
            low++, high--;
        }
    }
};