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
    ListNode *plusOne(ListNode *head) {
        auto dummy = head;
        stack<ListNode *> stk;
        while (dummy) {
            stk.push(dummy);
            dummy = dummy->next;
        }
        int carry = 1;
        while (!stk.empty()) {
            auto node = stk.top();
            int sum = node->val + carry;
            node->val = sum % 10;
            carry = sum / 10;
            stk.pop();
        }
        if (carry) {
            auto new_head = new ListNode(1);
            new_head->next = head;
            return new_head;
        }
        return head;
    }
};