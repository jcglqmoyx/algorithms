from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.res = -10 ** 9

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode]) -> int:
            if not node:
                return -10 ** 9
            left = dfs(node.left)
            right = dfs(node.right)
            self.res = max(self.res, left, right, node.val, node.val + left, node.val + right, node.val + left + right)

            return max(node.val, node.val + left, node.val + right)

        dfs(root)
        return self.res
