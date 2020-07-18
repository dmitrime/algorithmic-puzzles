import random
class RandomizedSet:

    def __init__(self):
        self.ns = []
        self.pos = {}
        

    def insert(self, val: int) -> bool:
        if val not in self.pos:
            self.pos[val] = len(self.ns)
            self.ns.append(val)
            return True
        return False


    def remove(self, val: int) -> bool:
        if val in self.pos:
            idx, last = self.pos[val], self.ns[-1]
            self.ns[idx] = last
            self.pos[last] = idx
            self.ns.pop()
            self.pos.pop(val, 0)
            return True
        return False
        

    def getRandom(self) -> int:
        r = random.randint(0, len(self.ns)-1)
        return self.ns[r]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
