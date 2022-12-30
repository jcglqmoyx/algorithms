#include <bits/stdc++.h>

using namespace std;

class ImmutableListNode {
public:
    void printValue();

    ImmutableListNode *getNext();
};

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode *head) {
        stack<ImmutableListNode *> stk;
        while (head) {
            stk.push(head);
            head = head->getNext();
        }
        while (!stk.empty()) {
            stk.top()->printValue();
            stk.pop();
        }
    }
};