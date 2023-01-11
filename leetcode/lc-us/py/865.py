import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        Node = collections.namedtuple("Node", ("node", "max_depth"))

        def dfs(node: TreeNode) -> Node:
            if not node:
                return Node(None, 0)
            left = dfs(node.left)
            right = dfs(node.right)
            if left[1] == right[1]:
                return Node(node, left[1] + 1)
            elif left[1] > right[1]:
                return Node(left[0], left[1] + 1)
            else:
                return Node(right[0], right[1] + 1)

        return dfs(root).node
