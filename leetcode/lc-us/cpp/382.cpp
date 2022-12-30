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
    ListNode *p;

public:
    Solution(ListNode *head) {
        p = head;
    }

    int getRandom() {
        ListNode *temp = p;
        int count = 1;
        int ans = 0;
        while (temp) {
            if (rand() % count == 0) {
                ans = temp->val;
            }
            count++;
            temp = temp->next;
        }
        return ans;
    }
};