class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.N = capacity
        self.pos = dict()
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def putFront(self, p):
        if p.next is not None:
            p.prev.next = p.next
        if p.prev is not None:
            p.next.prev = p.prev
        next = self.head.next
        p.next = next
        next.prev = p
        self.head.next = p
        p.prev = self.head
      
    def pprint(self):
        cur = self.head
        while cur:
            print(cur.key, end= " ")
            cur = cur.next
        print()
            
    def evict(self):
        p = self.tail.prev
        p.prev.next = self.tail
        self.tail.prev = p.prev
        p.next = p.prev = None
        del self.pos[p.key]
        
    def get(self, key: int) -> int:
        if key in self.pos:
            p = self.pos[key]
            self.putFront(p)
            return p.val
        return -1
            
    def put(self, key: int, value: int) -> None:
        if key in self.pos:
            p = self.pos[key]
            p.val = value
            self.putFront(p)
        elif self.N > 0:
            if len(self.pos) == self.N:
                self.evict()
            p = Node(key, value)
            self.pos[key] = p
            self.putFront(p)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
