#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        vector<int> res(arr1.size());
        vector<int> left;
        unordered_map<int, int> map;
        for (int i = 0; i < arr2.size(); i++) {
            map[arr2[i]] = i;
        }
        vector<int> arr;
        for (int num: arr1) {
            if (map.count(num)) {
                arr.push_back(num);
            } else {
                left.push_back(num);
            }
        }
        sort(arr.begin(), arr.end(), [&map](int a, int b) {
            return map[a] < map[b];
        });
        sort(left.begin(), left.end());
        int index = 0;
        for (int num: arr) {
            res[index++] = num;
        }
        for (int num: left) {
            res[index++] = num;
        }
        return res;
    }
};