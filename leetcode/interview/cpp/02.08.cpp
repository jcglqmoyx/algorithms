#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        auto slow = head, fast = head;
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast && fast->next && fast != slow);
        if (!fast || !fast->next) return nullptr;
        while (fast && head != fast) {
            fast = fast->next;
            head = head->next;
        }
        return head;
    }
};