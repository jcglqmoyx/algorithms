struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        auto dummy = head, second = head;
        ListNode *first;
        for (int i = 1; i < k; i++) {
            head = head->next;
        }
        first = head;
        auto fast = head;
        while (fast && fast->next) {
            fast = fast->next;
            second = second->next;
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return dummy;
    }
};