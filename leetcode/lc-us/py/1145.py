from collections import defaultdict

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        g = defaultdict(list)

        def dfs1(node: Optional[TreeNode]) -> None:
            if not node:
                return
            if node.left:
                g[node.val].append(node.left.val)
                g[node.left.val].append(node.val)
                dfs1(node.left)
            if node.right:
                g[node.val].append(node.right.val)
                g[node.right.val].append(node.val)
                dfs1(node.right)

        dfs1(root)

        def dfs2(u: int, p: int) -> int:
            res = 0
            for ne in g[u]:
                if ne != p:
                    res += dfs2(ne, u)
            return res + 1

        for y in g[x]:
            t = dfs2(y, x)
            if t > n // 2:
                return True
        return False
