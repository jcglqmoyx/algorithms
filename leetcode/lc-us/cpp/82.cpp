struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        auto dummy = new ListNode(0, head), cur = dummy;
        while (head) {
            if (head->next && head->val == head->next->val) {
                cur->next = nullptr;
                while (head && head->next && head->val == head->next->val) {
                    head = head->next;
                }
                if (head) {
                    head = head->next;
                }
            } else {
                cur->next = head;
                cur = cur->next;
                head = head->next;
            }
        }
        return dummy->next;
    }
};