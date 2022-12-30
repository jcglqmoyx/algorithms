#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        unordered_set<int> set;
        vector<int> arr;
        while (head) {
            if (!set.count(head->val)) {
                arr.push_back(head->val);
                set.insert(head->val);
            }
            head = head->next;
        }
        auto node = new ListNode(0), dummy = node;
        for (int val: arr) {
            node->next = new ListNode(val);
            node = node->next;
        }
        return dummy->next;
    }
};