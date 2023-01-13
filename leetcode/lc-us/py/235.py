class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val > q.val:
            t = p
            p = q
            q = t

        def dfs(node: 'TreeNode') -> 'TreeNode':
            if node:
                if p.val <= node.val <= q.val:
                    return node
                elif node.val > q.val:
                    return dfs(node.left)
                else:
                    return dfs(node.right)

        return dfs(root)
