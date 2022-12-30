#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head->val == val) return head->next;
        auto dummy = head;
        while (head && head->next) {
            if (head->next->val == val) {
                if (head->next->next) head->next = head->next->next;
                else head->next = nullptr;

            }
            head = head->next;
        }
        return dummy;
    }
};