struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        auto dummy = new ListNode(0, head);
        auto temp = dummy;
        while (temp->next && temp->next->next) {
            auto node1 = temp->next, node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};