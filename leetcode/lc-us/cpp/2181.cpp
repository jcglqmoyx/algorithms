struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        auto res = new ListNode(-1), cur = res;
        while (head) {
            auto node = head->next;
            int sum = 0;
            while (node && node->val) {
                sum += node->val;
                node = node->next;
            }
            if (sum) cur->next = new ListNode(sum);
            else break;
            cur = cur->next;
            head = node;
        }
        return res->next;
    }
};