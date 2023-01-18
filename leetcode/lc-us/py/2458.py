from collections import defaultdict

from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.mx = 0

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        depth = defaultdict(int)

        def dfs1(node: 'TreeNode', d: int):
            depth[node.val] = self.mx
            self.mx = max(self.mx, d)
            if node.left:
                dfs1(node.left, d + 1)
            if node.right:
                dfs1(node.right, d + 1)

        def dfs2(node: 'TreeNode', d: int):
            depth[node.val] = max(depth[node.val], self.mx)
            self.mx = max(self.mx, d)
            if node.right:
                dfs2(node.right, d + 1)
            if node.left:
                dfs2(node.left, d + 1)

        dfs1(root, 0)
        self.mx = 0
        dfs2(root, 0)
        return [depth[q] for q in queries]
