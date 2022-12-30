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
    ListNode *sortLinkedList(ListNode *head) {
        vector<ListNode *> nodes;
        for (auto p = head; p; p = p->next) {
            if (p->val < 0) nodes.push_back(p);
        }
        reverse(nodes.begin(), nodes.end());
        for (auto p = head; p; p = p->next) {
            if (p->val >= 0) nodes.push_back(p);
        }
        for (int i = 0; i < nodes.size() - 1; i++) nodes[i]->next = nodes[i + 1];
        nodes.back()->next = nullptr;
        return nodes.front();
    }
};