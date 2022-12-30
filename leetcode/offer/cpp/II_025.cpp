struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto node = new ListNode, res = node;
        l1 = reverse(l1), l2 = reverse(l2);
        int sum, carry = 0;
        while (l1 || l2) {
            if (l1 && l2) {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val + carry;
                l1 = l1->next;
            } else {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            carry = sum / 10;
            node->next = new ListNode;
            node->next->val = sum % 10;
            node = node->next;
        }
        if (carry) node->next = new ListNode(1);
        res = res->next;
        return reverse(res);
    }

private:
    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            auto next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};