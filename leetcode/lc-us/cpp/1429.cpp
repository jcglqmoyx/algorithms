#include <bits/stdc++.h>

using namespace std;

class FirstUnique {
    unordered_map<int, int> map;
    vector<int> arr;
    int ptr = 0;
public:
    FirstUnique(vector<int> &nums) {
        arr = nums;
        for (int &num: nums) {
            map[num]++;
        }
    }

    int showFirstUnique() {
        while (ptr < arr.size() && map[arr[ptr]] > 1) ptr++;
        return ptr < arr.size() ? arr[ptr] : -1;
    }

    void add(int value) {
        arr.push_back(value);
        map[value]++;
    }
};