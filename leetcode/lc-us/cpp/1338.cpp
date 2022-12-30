#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int> &arr) {
        int map[100000] = {};
        for (int num: arr) map[num - 1]++;
        int n = (int) arr.size();
        sort(map, map + 100000);
        int sum = 0;
        int count = 0;
        for (int i = 99999; i >= 0; i--) {
            sum += map[i];
            count++;
            if (sum >= n / 2) break;
        }
        return count;
    }
};