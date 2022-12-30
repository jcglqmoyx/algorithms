struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        auto dummy = new ListNode(-1, head);
        auto fast = dummy, slow = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!slow->next) return nullptr;
        if (!fast) slow->val = slow->next->val;
        slow->next = slow->next->next;
        return dummy->next;
    }
};