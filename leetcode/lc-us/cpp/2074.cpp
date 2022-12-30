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
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        auto res = new ListNode(-1, head), cur = res;
        int max_len = 1;
        while (true) {
            int len = 0;
            auto p = cur;
            for (; len < max_len && p->next; len++) p = p->next;
            ListNode *ne = p->next;
            p->next = nullptr;
            if (len % 2 == 0) cur->next = reverse(cur->next);
            while (cur->next) cur = cur->next;
            cur->next = ne;
            if (!ne) break;
            max_len++;
        }
        return res->next;
    }

private:
    static ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};