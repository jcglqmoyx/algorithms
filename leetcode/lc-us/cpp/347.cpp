#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> freq;

    void quick_select(vector<int> &elements, int k, int low, int high) {
        while (low < high) {
            int position = partition(elements, low, high);
            if (position < k - 1) low = position + 1;
            else high = position - 1;
        }
    }

    int partition(vector<int> &elements, int low, int high) {
        int random_index = rand() % (high - low + 1) + low;
        swap(elements[low], elements[random_index]);
        int pivot = freq[elements[low]];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && freq[elements[i]] > pivot) i++;
            while (j > low && freq[elements[j]] < pivot) j--;
            if (i >= j) break;
            swap(elements[i], elements[j]);
            i++, j--;
        }
        swap(elements[low], elements[j]);
        return j;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        for (int num: nums) freq[num]++;
        vector<int> elements;
        for (const auto &x: freq) {
            elements.push_back(x.first);
        }
        quick_select(elements, k, 0, (int) elements.size() - 1);
        return vector<int>(elements.begin(), elements.begin() + k);
    }
};