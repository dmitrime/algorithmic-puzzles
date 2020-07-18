# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        tab = defaultdict(list)
        
        def inorder(root, pos, lvl):
            if not root:
                return
            inorder(root.left, pos-1, lvl+1)
            tab[pos].append((lvl, root.val))
            inorder(root.right, pos+1, lvl+1)
        
        inorder(root, 0, 0)
        return [[v for _, v in sorted(vals)] for k, vals in sorted(tab.items())]
