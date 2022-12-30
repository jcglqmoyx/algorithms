#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int> &count) {
        int n = (int) count.size();
        vector<double> res(5);
        for (int i = 0; i < n; i++) {
            if (count[i]) {
                res[0] = i;
                break;
            }
        }
        for (int i = n - 1; ~i; i--) {
            if (count[i]) {
                res[1] = i;
                break;
            }
        }
        double sum = 0;
        int cnt = 0, max_freq = 0, mode = 0;
        for (int i = 0; i < n; i++) {
            sum += (double) i * count[i];
            cnt += count[i];
            if (count[i] > max_freq) {
                max_freq = count[i];
                mode = i;
            }
        }
        res[2] = sum / cnt, res[4] = mode;
        if (cnt & 1) res[3] = get(count, cnt / 2 + 1);
        else res[3] = (double) (get(count, cnt / 2) + get(count, cnt / 2 + 1)) / 2;
        return res;
    }

private:
    template<typename T>
    T get(vector<T> &nums, T idx) {
        T cnt = 0;
        for (T i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            if (cnt >= idx) return i;
        }
        return 0;
    }
};