#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        int map[37] = {};
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            map[sum]++;
        }
        sort(map, map + 37);
        int count = 0;
        int max = map[36];
        for (int i = 36; i >= 1; i--) {
            if (map[i] == max) {
                count++;
            } else {
                return count;
            }
        }
        return 1;
    }
};