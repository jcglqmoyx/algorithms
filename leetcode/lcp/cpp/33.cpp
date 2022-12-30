#include <bits/stdc++.h>

using namespace std;

class Solution {
    static int cnt(int bucket, int vat) {
        return bucket >= vat ? 1 : vat % bucket ? vat / bucket + 1 : vat / bucket;
    }

    struct cmp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return cnt(a.first, a.second) < cnt(b.first, b.second);
        }
    };

public:
    int storeWater(vector<int> &bucket, vector<int> &vat) {
        int vat_sum = 0;
        int count = 0;
        int n = (int) bucket.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (int i = 0; i < n; i++) {
            if (bucket[i] == 0 && vat[i]) {
                count++;
                bucket[i]++;
            }
            vat_sum += vat[i];
            q.push({bucket[i], vat[i]});
        }
        if (vat_sum == 0) return 0;
        int res = count + cnt(q.top().first, q.top().second);
        int increase = 0;
        while (increase <= 10000) {
            increase++;
            pair<int, int> top = q.top();
            q.pop();
            q.push({top.first + 1, top.second});
            int cur = cnt(q.top().first, q.top().second) + increase + count;
            if (cur <= res) {
                res = cur;
            }
        }
        return res;
    }
};