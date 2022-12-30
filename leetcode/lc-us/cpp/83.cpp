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
        auto *dummy = new ListNode(0);
        dummy->next = head;
        while (head && head->next) {
            while (head->next && head->val == head->next->val) {
                head->next = head->next->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};