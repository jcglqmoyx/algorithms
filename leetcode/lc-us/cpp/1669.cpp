struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        auto dummy = list1;
        for (int i = 1; i < a; i++) list1 = list1->next;
        auto start = list1;
        for (int i = 0; i <= b - a; i++) start = start->next;
        list1->next = list2;
        while (list2 && list2->next) list2 = list2->next;
        list2->next = start->next;
        return dummy;
    }
};