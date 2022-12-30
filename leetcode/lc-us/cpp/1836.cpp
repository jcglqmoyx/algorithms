#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        unordered_map<int, int> hash;
        auto cur = head;
        while (cur) {
            hash[cur->val]++;
            cur = cur->next;
        }
        auto dummy = new ListNode();
        cur = dummy;
        while (head) {
            auto next = head->next;
            if (hash[head->val] == 1) {
                cur->next = head;
                cur = head;
                cur->next = nullptr;
            }
            head = next;
        }
        return dummy->next;
    }
};