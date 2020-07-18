# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    def __init__(self, root: TreeNode):
        self.st = []
        while root:
            self.st.append(root)
            root = root.left

    def next(self) -> int:
        if self.st:
            node = self.st.pop()
            r = node.right
            while r:
                self.st.append(r)
                r = r.left
            return node.val
        return None

    def hasNext(self) -> bool:
        return len(self.st) > 0
        

# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
