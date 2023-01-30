class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        cur = list1
        first = None
        for i in range(b):
            if i == a - 1:
                first = cur
            cur = cur.next
        second = cur.next
        first.next = list2
        while first and first.next:
            first = first.next
        first.next = second
        return list1
