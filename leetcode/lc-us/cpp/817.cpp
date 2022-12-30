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
    int numComponents(ListNode *head, vector<int> &nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int prev = -2;
        int count = 0;
        while (head) {
            if (set.count(prev) && set.count(head->val)) {
                count++;
            }
            prev = head->val;
            head = head->next;
        }
        return (int) nums.size() - count;
    }
};