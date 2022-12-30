struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        auto smaller = new ListNode(0, head);
        auto smaller_head = smaller;
        auto larger = new ListNode(0, head);
        auto larger_head = larger;
        while (head) {
            if (head->val >= x) {
                larger_head->next = head;
                larger_head = head;
            } else {
                smaller_head->next = head;
                smaller_head = head;
            }
            head = head->next;
        }
        larger_head->next = nullptr;
        smaller_head->next = larger->next;
        return smaller->next;
    }
};