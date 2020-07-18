# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        q = [root]
        nodes = []
        while q:
            n = q.pop(0)
            nodes.append(str(n.val) if n else '#')
            if n:
                q.append(n.left)
                q.append(n.right)
        return ','.join(nodes)
        
    
    def deserialize(self, data):
        if not data:
            return None
        vals = [None if d == '#' else TreeNode(d) for d in data.split(',')]
        q = [vals[0]]
        idx = 1
        while q and idx < len(vals):
            n = q.pop(0)
            if vals[idx] is not None:
                n.left = vals[idx]
                q.append(n.left)
            idx += 1
            if vals[idx] is not None:
                n.right = vals[idx]
                q.append(n.right)
            idx += 1
        return vals[0]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
