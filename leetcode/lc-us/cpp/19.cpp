struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto dummy = new ListNode(0, head);
        auto first = head, second = dummy;
        for (int i = 0; i < n; i++) first = first->next;
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};