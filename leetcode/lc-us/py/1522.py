class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []


class Solution:
    def __init__(self):
        self.res = 0

    def diameter(self, root: 'Node') -> int:
        def dfs(node: 'Node') -> int:
            if not node:
                return 0
            a = b = 0
            for child in node.children:
                t = dfs(child)
                if t > a:
                    b, a = a, t
                elif t > b:
                    b = t
            self.res = max(self.res, a + b)
            return max(a, b) + 1

        dfs(root)
        return self.res
