struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        auto dummy = new ListNode(0, head), node = dummy;
        while (node && node->next) {
            while (node->next && node->next->val == val) {
                node->next = node->next->next;
            }
            node = node->next;
        }
        return dummy->next;
    }
};