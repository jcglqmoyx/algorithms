#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> nums;
        ListNode *node = head;
        while (node) {
            nums.push_back(node->val);
            node = node->next;
        }
        int n = (int) nums.size();
        stack<int> s;
        vector<int> res(n);
        for (int i = n - 1; ~i; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) s.pop();
            if (!s.empty()) res[i] = nums[s.top()];
            else res[i] = 0;
            s.push(i);
        }
        return res;
    }
};